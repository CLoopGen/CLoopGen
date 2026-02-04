#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop() {
    for (y = 0; y < height; y++) {
        uint16_t *src_row = src + y * slinesize;
        uint16_t *dst_row = dst + y * dlinesize;
        uint16_t *index_row = (uint16_t*)((char*)index + (y << 1) * ilinesize);
        for (x = 0; x < width; x++) {
            int idx = index_row[x << 1];
            int v = (idx >= 0 && idx < (1 << 20)) ? lut[idx] : 0;
            dst_row[x] = (v >= 0 && v <= max) ? v : src_row[x];
        }
    }
}
