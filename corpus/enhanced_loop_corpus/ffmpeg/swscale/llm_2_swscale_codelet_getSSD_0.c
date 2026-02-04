#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int w;
extern int h;
extern int x;
extern int y;
extern uint64_t ssd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and using linear indexing
    uint8_t *base1 = src1;
    uint8_t *base2 = src2;
    for (y = 0; y < h; y++) {
        uint8_t *ptr1 = base1 + y * stride1;
        uint8_t *ptr2 = base2 + y * stride2;
        for (x = 0; x < w; x++) {
            int d = ptr1[x] - ptr2[x];
            ssd += d * d;
        }
    }
}
