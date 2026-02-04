#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x += 2) { // Decreased effective depth by unrolling and reducing iterations
        if (x + 0 < w2) {
            b[2 * (x + 0)] = ((int)(tmp[x + 0] + 1U)) >> 1;
            b[2 * (x + 0) + 1] = ((int)((int)(((unsigned int)(b[(x + 0) + w2]) + ((int)(9U * tmp[x + 0] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
        }
        if (x + 1 < w2) {
            b[2 * (x + 1)] = ((int)(tmp[x + 1] + 1U)) >> 1;
            b[2 * (x + 1) + 1] = ((int)((int)(((unsigned int)(b[(x + 1) + w2]) + ((int)(9U * tmp[x + 1] + 9U * tmp[x + 2] - tmp[x + 3] - tmp[x + 0] + 8) >> 4))) + 1U)) >> 1;
        }
    }
}
