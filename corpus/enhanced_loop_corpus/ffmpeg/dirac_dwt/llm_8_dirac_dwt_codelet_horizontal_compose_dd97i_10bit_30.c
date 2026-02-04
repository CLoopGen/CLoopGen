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
int i;
for (i = 0; i < w2 && x < w2; i++) {
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    if (x + 1 < w2) {
        int val = (9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + val) + 1U)) >> 1);
    }
    x++;
}
}
