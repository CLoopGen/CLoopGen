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
    uint8_t *dst = hnm->processed;
    const uint8_t *src_base = hnm->current;
    for (y = 0; y < hnm->height; y++) {
        src_y = y - (y % 2);
        const uint8_t *src = src_base + src_y * width + (y % 2);
        for (x = 0; x < width; x++, dst++, src += 2) {
            *dst = *src;
        }
    }
}
