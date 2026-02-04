#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Hnm4VideoContext {
    uint8_t version;
    int width;
    int height;
    uint8_t *current;
    uint8_t *previous;
    uint8_t *buffer1;
    uint8_t *buffer2;
    uint8_t *processed;
    uint32_t palette[256];
} Hnm4VideoContext;

extern Hnm4VideoContext *hnm;
extern uint32_t x;
extern uint32_t y;
extern uint32_t src_y;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < hnm->height; y++) {
    uint8_t *dst = hnm->processed + y * width;
    const uint8_t *src_base = hnm->current;
    src_y = y - (y % 2);
    const uint8_t *src = src_base + src_y * width + (y % 2);
    x = 0;
    while (x + 3 < width) {
        dst[x]   = src[0];
        dst[x+1] = src[2];
        dst[x+2] = src[4];
        dst[x+3] = src[6];
        src += 8;
        x += 4;
    }
    for (; x < width; x++) {
        dst[x] = *src;
        src += 2;
    }
}
}
