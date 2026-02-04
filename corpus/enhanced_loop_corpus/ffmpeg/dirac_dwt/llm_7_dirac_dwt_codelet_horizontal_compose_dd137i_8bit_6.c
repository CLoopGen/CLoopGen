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
int prev_temp = 0;
for (x = 0; x < w2; x++) {
    int current_tmp = (int)(tmp[x] + 1U) >> 1;
    b[2 * x] = prev_temp;
    prev_temp = current_tmp;
    if (x > 0) {
        int combined = ((int)((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U;
        b[2 * x - 1] = combined >> 1;
    }
}
if (w2 > 0) {
    b[2 * w2 - 1] = ((int)((unsigned int)(b[w2 - 1 + w2]) + ((int)(9U * tmp[w2 - 1] + 9U * tmp[w2] - tmp[w2 + 1] - tmp[w2 - 2] + 8) >> 4)) + 1U) >> 1;
}
}
