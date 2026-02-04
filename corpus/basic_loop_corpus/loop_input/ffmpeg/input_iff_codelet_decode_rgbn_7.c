#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int width = 1920;
int height = 1080;
int linesize = 1920 * sizeof(uint16_t);
int x = 0;
int y = 0;
int i;
int length = 2073600; // 1920 * 1080 pixels
uint32_t pixel = 0x5A5A;

void init_vars() {
    dst = aligned_alloc(16, (size_t)linesize * height);
    if (!dst) {
        exit(1);
    }
}