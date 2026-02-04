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
for (x = 0; x < w2; x += 2) {
    if (x + 1 < w2) {
        b[2 * x] = ((int)(tmp[x] + 2U)) >> 1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(7U * tmp[x] + 7U * tmp[x + 1] + 8) >> 3))) + 1U)) >> 1;
        b[2 * (x + 1)] = ((int)(tmp[x + 1] + 2U)) >> 1;
        b[2 * (x + 1) + 1] = ((int)((int)(((unsigned int)(b[(x + 1) + w2]) + ((int)(7U * tmp[x + 1] + 7U * tmp[x + 2] + 8) >> 3))) + 1U)) >> 1;
    } else {
        b[2 * x] = ((int)(tmp[x] + 2U)) >> 1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(7U * tmp[x] + 7U * tmp[x + 1] + 8) >> 3))) + 1U)) >> 1;
    }
}
}
