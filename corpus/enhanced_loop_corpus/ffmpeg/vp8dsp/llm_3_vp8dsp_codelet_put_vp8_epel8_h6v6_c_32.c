#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect indexing via precomputed indices to simulate irregular memory access
    int indices[8];
    for (int i = 0; i < 8; i++) {
        indices[i] = i; // Base indices, could be randomized or reordered in practice
    }

    for (y = 0; y < h + 6 - 1; y++) {
        for (x = 0; x < 8; x++) {
            int idx = indices[x]; // Indirect access through index array
            int val = filter[2] * src[idx + 0] -
                      filter[1] * src[idx - 1] +
                      filter[0] * src[idx - 2] +
                      filter[3] * src[idx + 1] -
                      filter[4] * src[idx + 2] +
                      filter[5] * src[idx + 3];
            tmp[idx] = cm[(val + 64) >> 7]; // Write scattered output
        }
        tmp += 8;
        src += srcstride;
    }
}
