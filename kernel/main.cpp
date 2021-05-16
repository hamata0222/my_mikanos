/**
 * @file main.cpp
 *
 * カーネル本体のプログラムを書いたファイル
 */

#include <cstdint>
#include <cstddef>
#include <cstdio>

#include  "graphics.hpp"
#include  "font.hpp"

void* operator new(size_t size, void* buf) {
  return buf;
}

void operator delete(void* obj) noexcept {
}

char pixel_writer_buf[sizeof(RGBResv8BitPerColorPixelWriter)]; // PixelWriteのインスタンスを配置する領域
PixelWriter* pixel_writer;

extern "C" void KernelMain(const FrameBufferConfig& frame_buffer_config) {
  switch (frame_buffer_config.pixel_format) {
    case kPixelRGBResv8BitPerColor:
      pixel_writer = new(pixel_writer_buf)
        RGBResv8BitPerColorPixelWriter{frame_buffer_config};
      break;
    case kPixelBGRResv8BitPerColor:
      pixel_writer = new(pixel_writer_buf)
        BGRResv8BitPerColorPixelWriter{frame_buffer_config};
      break;
  }

  for (int x = 0; x < frame_buffer_config.horizontal_resolution; ++x) {
    for (int y = 0; y < frame_buffer_config.vertical_resolution; ++y) {
      pixel_writer->Write(x, y, {255, 255, 255});
    }
  }
  for (int x = 0; x < 200; ++x) {
    for (int y = 0; y < 100; ++y) {
      pixel_writer->Write(100 + x, 100 + y, {0, 255, 0});
    }
  }

  int i = 0;
  for (char c = '!'; c <= '~'; ++c, ++i) {
    WriteAscii(*pixel_writer, 8 * i, 150, c, {0, 0, 0});
  }

  WriteString(*pixel_writer, 0, 166, "Hello World.", {0, 0, 0});

  char buf[128];
  sprintf(buf, "1 + 2 = %d", 1 + 2);
  WriteString(*pixel_writer, 0, 182, buf, {0, 0, 0});

  while (1) __asm__("hlt");
}

