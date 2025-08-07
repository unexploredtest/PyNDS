import pygame
import numpy as np


class Window:
    def __init__(self, pynds) -> None:
        self._pynds = pynds
        self.is_gba = pynds.get_is_gba()

        self.running = False

    def init(self, width: int, height: int) -> None:
        pygame.init()
        self.screen = pygame.display.set_mode((width, height), pygame.RESIZABLE)
        pygame.display.set_caption("PyNDS")

        self.running = True

    def close(self) -> None:
        pygame.quit()
        self.running = False

    def render(self) -> None:
        if (self.running):
            self.handle_events()

            if (self.is_gba and self.running):
                self.process_frame_gba()
            elif (self.running):
                self.process_frame_nds()

    def handle_events(self) -> None:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.close()

            if event.type == pygame.MOUSEMOTION:
                width, height = self.screen.get_size()
                mid_height = height // 2
                x, y = event.pos
                if (y > mid_height):
                    scale_y = mid_height / 192
                    y -= mid_height
                    y = int(y / scale_y)

                    scale_x = width / 256
                    x = int(x / scale_x)
                    self._pynds.button.set_touch(x, y)
                else:
                    self._pynds.button.clear_touch()

            if event.type == pygame.MOUSEBUTTONDOWN:
                self._pynds.button.touch()

            if event.type == pygame.MOUSEBUTTONUP:
                self._pynds.button.release_touch()

            if event.type == pygame.KEYDOWN:  # Check for key press events
                if event.key == pygame.K_w:
                    self._pynds.button.press_key('up')
                if event.key == pygame.K_d:
                    self._pynds.button.press_key('right')
                if event.key == pygame.K_a:
                    self._pynds.button.press_key('left')
                if event.key == pygame.K_s:
                    self._pynds.button.press_key('down')
                if event.key == pygame.K_p:
                    self._pynds.button.press_key('start')
                if event.key == pygame.K_o:
                    self._pynds.button.press_key('select')
                if event.key == pygame.K_l:
                    self._pynds.button.press_key('a')
                if event.key == pygame.K_k:
                    self._pynds.button.press_key('b')
                if event.key == pygame.K_i:
                    self._pynds.button.press_key('x')
                if event.key == pygame.K_j:
                    self._pynds.button.press_key('y')
                if event.key == pygame.K_e:
                    self._pynds.button.press_key('l')
                if event.key == pygame.K_u:
                    self._pynds.button.press_key('r')

            if event.type == pygame.KEYUP:  # Check for key release events
                if event.key == pygame.K_w:
                    self._pynds.button.release_key('up')
                if event.key == pygame.K_d:
                    self._pynds.button.release_key('right')
                if event.key == pygame.K_a:
                    self._pynds.button.release_key('left')
                if event.key == pygame.K_s:
                    self._pynds.button.release_key('down')
                if event.key == pygame.K_p:
                    self._pynds.button.release_key('start')
                if event.key == pygame.K_o:
                    self._pynds.button.release_key('select')
                if event.key == pygame.K_l:
                    self._pynds.button.release_key('a')
                if event.key == pygame.K_k:
                    self._pynds.button.release_key('b')
                if event.key == pygame.K_i:
                    self._pynds.button.release_key('x')
                if event.key == pygame.K_j:
                    self._pynds.button.release_key('y')
                if event.key == pygame.K_e:
                    self._pynds.button.release_key('l')
                if event.key == pygame.K_u:
                    self._pynds.button.release_key('r')

    def process_frame_gba(self) -> None:
        width, height = self.screen.get_size()

        frame = self._pynds.get_frame()
        frame = frame.reshape((frame.shape[1], frame.shape[0], 4))
        frame = np.ascontiguousarray(frame)

        surface = pygame.image.frombuffer(frame, (frame.shape[0], frame.shape[1]), 'RGBA')
        surface = pygame.transform.scale(surface, (width, height))

        self.screen.blit(surface, surface.get_rect(topleft=(0, 0)))
        pygame.display.flip()

    def process_frame_nds(self):
        width, height = self.screen.get_size()

        frame_top, frame_bot = self._pynds.get_frame()

        frame_top = frame_top.reshape((frame_top.shape[1], frame_top.shape[0], 4))
        frame_top = np.ascontiguousarray(frame_top)
        frame_bot = frame_bot.reshape((frame_bot.shape[1], frame_bot.shape[0], 4))
        frame_bot = np.ascontiguousarray(frame_bot)

        surface = pygame.image.frombuffer(frame_top, (frame_top.shape[0], frame_top.shape[1]), 'RGBA')
        surface = pygame.transform.scale(surface, (width, height // 2))
        self.screen.blit(surface, surface.get_rect(topleft=(0, 0)))

        surface = pygame.image.frombuffer(frame_bot, (frame_bot.shape[0], frame_bot.shape[1]), 'RGBA')
        surface = pygame.transform.scale(surface, (width, height // 2))
        self.screen.blit(surface, surface.get_rect(topleft=(0, height // 2)))

        pygame.display.flip()
