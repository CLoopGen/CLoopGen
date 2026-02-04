#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int y = 0; y < w2; y += 2) { // Decreased effective depth by unrolling and processing two iterations per loop step
        if (y < w2) {
            x = y;
            b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
            b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
        }
        if (y + 1 < w2) {
            x = y + 1;
            b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
            b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
        }
    }
}
