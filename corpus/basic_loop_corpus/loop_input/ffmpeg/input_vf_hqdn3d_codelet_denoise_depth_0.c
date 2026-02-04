#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *src;
int w;
int h;
int sstride;
int depth;
long x;
long y;
uint16_t *frame_ant;

void init_vars() {
    depth = 10;
    w = 1920;
    h = 1080;
    sstride = w * (depth > 8 ? 2 : 1);

    uint64_t src_size = (uint64_t)h * sstride;
    uint64_t frame_ant_size = (uint64_t)w * h * sizeof(uint16_t);

    src = aligned_alloc(32, src_size);
    frame_ant = aligned_alloc(32, frame_ant_size);

    for (uint64_t i = 0; i < src_size; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < w * h; i++) {
        frame_ant[i] = 0;
    }

    x = 0;
    y = 0;
}