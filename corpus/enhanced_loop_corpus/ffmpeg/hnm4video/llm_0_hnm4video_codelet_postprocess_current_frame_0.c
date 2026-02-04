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
    for (y = 0; y < hnm->height; y += 2) {
        uint8_t *dst1 = hnm->processed + y * width;
        uint8_t *dst2 = (y + 1 < hnm->height) ? hnm->processed + (y + 1) * width : NULL;
        const uint8_t *src = hnm->current + y * width;
        for (x = 0; x < width; x++) {
            dst1[x] = src[x * 2];
            if (dst2) {
                dst2[x] = src[x * 2 + 1];
            }
        }
    }
}
