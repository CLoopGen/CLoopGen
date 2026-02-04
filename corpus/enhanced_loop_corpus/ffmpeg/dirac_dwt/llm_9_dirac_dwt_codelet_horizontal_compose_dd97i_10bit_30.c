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
int step = 2;
for (x = 0; x < w2 - 1; x += step) {
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;

    if (x + 1 < w2) {
        b[2 * (x + 1)] = ((int)(tmp[x + 1] + 1U)) >> 1;
        b[2 * (x + 1) + 1] = ((int)((int)(((unsigned int)(b[(x + 1) + w2]) + ((int)(9U * tmp[x + 1] + 9U * tmp[x + 2] - tmp[x + 3] - tmp[x] + 8) >> 4))) + 1U)) >> 1;
    }
}
}
