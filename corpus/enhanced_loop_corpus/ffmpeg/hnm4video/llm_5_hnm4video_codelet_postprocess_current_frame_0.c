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
        const uint8_t *src = hnm->current;
        src_y = y & ~1u; // Equivalent to y - (y % 2), using bitwise clear of LSB
        src += src_y * width + (y & 1u);
        for (x = 0; x < width; x++) {
            if (x & 1) {
                dst[x] = *(src - 1); // Use previous byte on odd indices
            } else {
                dst[x] = *src;
            }
            src += 2;
        }
    }
}
