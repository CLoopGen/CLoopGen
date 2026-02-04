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
    b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
    int pred_index = x - 1;
    int base_val = (int)(((unsigned int)(b[pred_index + w2]) + ((int)(9U * tmp[pred_index] + 9U * tmp[pred_index + 1] - tmp[pred_index + 2] - tmp[pred_index - 1] + 8) >> 4))) + 1U;
    b[2 * pred_index + 1] = base_val >> 1;
}
if (w2 > 0) {
    b[2 * 0] = ((int)(tmp[0] + 1U)) >> 1;
}
if (w2 > 1) {
    int last = w2 - 1;
    b[2 * last] = ((int)(tmp[last] + 1U)) >> 1;
}
}
