#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= w2; stride *= 2) { // Decreased effective depth by transforming into logarithmic outer progression
        for (x = 0; x < w2; x += stride) {
            if (x + stride/2 < w2) {
                // Process two iterations per step to maintain semantic proximity
                int x1 = x;
                b[2 * x1] = ((int)(tmp[x1] + 1U)) >> 1;
                b[2 * x1 + 1] = ((int)((int)(((unsigned int)(b[x1 + w2]) + ((int)(9U * tmp[x1] + 9U * tmp[x1 + 1] - tmp[x1 + 2] - tmp[x1 - 1] + 8) >> 4))) + 1U)) >> 1;

                int x2 = x + stride/2;
                if (x2 < w2) {
                    b[2 * x2] = ((int)(tmp[x2] + 1U)) >> 1;
                    b[2 * x2 + 1] = ((int)((int)(((unsigned int)(b[x2 + w2]) + ((int)(9U * tmp[x2] + 9U * tmp[x2 + 1] - tmp[x2 + 2] - tmp[x2 - 1] + 8) >> 4))) + 1U)) >> 1;
                }
            } else {
                b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
                b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
            }
        }
    }
}
