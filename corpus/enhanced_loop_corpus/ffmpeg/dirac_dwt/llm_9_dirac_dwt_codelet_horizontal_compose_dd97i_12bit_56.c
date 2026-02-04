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
for (x = 1; x < w2 - 1; x++) {
    int val1 = (9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4;
    int val2 = (9U * tmp[x - 1] + 9U * tmp[x] - tmp[x + 1] - tmp[x - 2] + 8) >> 4;
    unsigned int sum1 = (unsigned int)(b[x + w2]) + val1;
    unsigned int sum2 = (unsigned int)(b[x - 1 + w2]) + val2;
    b[2 * x] = ((int)(sum1 + 1U)) >> 1;
    b[2 * x - 1] = ((int)(sum2 + 1U)) >> 1;
}
}
