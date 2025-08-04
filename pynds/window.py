import sdl2
import sdl2.ext
import ctypes


class Window:
    def __init__(self, pynds) -> None:
        self._pynds = pynds
        self.init()

    def init(self, width=720, height=480) ->  None:
        # width=512, height=768
        # 160, 240
        sdl2.ext.init()
        self.window = sdl2.ext.Window("PyNDS", size=(width, height), flags=sdl2.SDL_WINDOW_RESIZABLE)
        self.window.show()

        self.renderer = sdl2.ext.Renderer(self.window)
        self.image_shape = self._pynds.get_frame_shape()
        self.create_textures()
    
    def create_textures(self):
        if(self._pynds.get_is_gba()):
            self.texture = sdl2.SDL_CreateTexture(self.renderer.renderer,
                                        sdl2.SDL_PIXELFORMAT_ABGR8888,
                                        sdl2.SDL_TEXTUREACCESS_STATIC,
                                        self.image_shape[1], self.image_shape[0])
        else:
            self.texture_top = sdl2.SDL_CreateTexture(self.renderer.renderer,
                                        sdl2.SDL_PIXELFORMAT_ABGR8888,
                                        sdl2.SDL_TEXTUREACCESS_STATIC,
                                        self.image_shape[1], self.image_shape[0])
            self.texture_bot = sdl2.SDL_CreateTexture(self.renderer.renderer,
                                        sdl2.SDL_PIXELFORMAT_ABGR8888,
                                        sdl2.SDL_TEXTUREACCESS_STATIC,
                                        self.image_shape[1], self.image_shape[0])
    
    def update_textures(self):
        if(self._pynds.get_is_gba()):
            frame = self._pynds.get_frame()
            sdl2.SDL_UpdateTexture(self.texture, None, frame.ctypes.data, frame.shape[1] * 4)
        else:
            frame_top, frame_bot = self._pynds.get_frame()
            sdl2.SDL_UpdateTexture(self.texture_top, None, frame_top.ctypes.data, frame_top.shape[1] * 4)
            sdl2.SDL_UpdateTexture(self.texture_bot, None, frame_bot.ctypes.data, frame_bot.shape[1] * 4)

    def sdl_render(self):
        # print(self.window.size)
        # sdl2.SDL_GetWindowSize(self.window, width, height)
        width, height = self.window.size

        if(self._pynds.get_is_gba()):
            dest_rect = sdl2.SDL_Rect(0, 0, width, height)
            sdl2.SDL_RenderCopy(self.renderer.renderer, self.texture, None, dest_rect)
        else:
            dest_rect_top = sdl2.SDL_Rect(0, 0, width, height // 2)
            sdl2.SDL_RenderCopy(self.renderer.renderer, self.texture_top, None, dest_rect_top)

            dest_rect_bot = sdl2.SDL_Rect(0, height // 2, width, height // 2)
            sdl2.SDL_RenderCopy(self.renderer.renderer, self.texture_bot, None, dest_rect_bot)

    def process_events(self) -> bool:
        for event in sdl2.ext.get_events():
            if event.type == sdl2.SDL_QUIT:
                sdl2.ext.quit()
                return False

            if event.type == sdl2.SDL_KEYDOWN:
                if event.key.keysym.sym == sdl2.SDLK_w:
                    self._pynds.button.press_key('up')
                elif event.key.keysym.sym == sdl2.SDLK_d:
                    self._pynds.button.press_key('right')
                elif event.key.keysym.sym == sdl2.SDLK_a:
                    self._pynds.button.press_key('left')
                elif event.key.keysym.sym == sdl2.SDLK_s:
                    self._pynds.button.press_key('down')
                elif event.key.keysym.sym == sdl2.SDLK_p:
                    self._pynds.button.press_key('start')
                elif event.key.keysym.sym == sdl2.SDLK_o:
                    self._pynds.button.press_key('select')
                elif event.key.keysym.sym == sdl2.SDLK_k:
                    self._pynds.button.press_key('a')
                elif event.key.keysym.sym == sdl2.SDLK_l:
                    self._pynds.button.press_key('b')

            if event.type == sdl2.SDL_KEYUP:
                if event.key.keysym.sym == sdl2.SDLK_w:
                    self._pynds.button.release_key('up')
                elif event.key.keysym.sym == sdl2.SDLK_d:
                    self._pynds.button.release_key('right')
                elif event.key.keysym.sym == sdl2.SDLK_a:
                    self._pynds.button.release_key('left')
                elif event.key.keysym.sym == sdl2.SDLK_s:
                    self._pynds.button.release_key('down')
                elif event.key.keysym.sym == sdl2.SDLK_p:
                    self._pynds.button.release_key('start')
                elif event.key.keysym.sym == sdl2.SDLK_o:
                    self._pynds.button.release_key('select')
                elif event.key.keysym.sym == sdl2.SDLK_k:
                    self._pynds.button.release_key('a')
                elif event.key.keysym.sym == sdl2.SDLK_l:
                    self._pynds.button.release_key('b')

        return True

    def process_frame(self):
        # self.renderer.clear(sdl2.ext.Color(0, 0, 0))
    
        if(self.image_shape != self._pynds.get_frame_shape()):
            self.image_shape = self._pynds.get_frame_shape()
            self.create_textures()

        # Clear the renderer
        sdl2.SDL_RenderClear(self.renderer.renderer)

        self.sdl_render()

        # Present the renderer
        sdl2.SDL_RenderPresent(self.renderer.renderer)
        self.update_textures()

        self.renderer.present()

    def advance(self):
        self.process_events()
        self.process_frame()