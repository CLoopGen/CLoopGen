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
for (x = 0; x < w2 && x + 2 < w2; x++) {
    int t0 = tmp[x];
    int t1 = tmp[x + 1];
    int t2 = tmp[x + 2];
    int t_minus = tmp[x - 1 >= 0 ? x - 1 : 0];
    int val1 = (t0 + 1U) >> 1;
    int filtered = (9U * t0 + 9U * t1 - t2 - t_minus + 8) >> 4;
    int val2 = ((int)((unsigned int)(b[x + w2]) + filtered) + 1U) >> 1;
    b[2 * x] = val1;
    b[2 * x + 1] = val2;
}
}
