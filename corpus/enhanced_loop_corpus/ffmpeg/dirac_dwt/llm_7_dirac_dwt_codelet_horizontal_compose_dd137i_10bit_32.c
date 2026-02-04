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
for (x = 1; x < w2 - 1; x++) {
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    int base = (int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4;
    int combined = ((int)((unsigned int)(b[x + w2]) + base) + 1U) >> 1;
    b[2 * x + 1] = combined;
}
if (w2 > 0) {
    x = 0;
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    b[2 * x + 1] = ((int)((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] + 8) >> 4)) + 1U) >> 1;
}
if (w2 > 1) {
    x = w2 - 1;
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    b[2 * x + 1] = ((int)((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] - tmp[x - 1] + 8) >> 4)) + 1U) >> 1;
}
}
