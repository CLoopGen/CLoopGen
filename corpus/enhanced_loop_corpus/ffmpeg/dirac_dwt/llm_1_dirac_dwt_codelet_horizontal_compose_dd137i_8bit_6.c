#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (w2 > 0) {
    x = 0;
    for (int outer = 0; outer < w2; outer++) {
        b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
        x++;
    }
}
}
