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
for (x = 0; x < w2; x++) {
    int temp_val = ((int)(tmp[x] + 1U)) >> 1;
    b[2 * x] = temp_val;
    if (x + 1 < w2 && x - 1 >= 0) {
        int filtered = (int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U;
        b[2 * x + 1] = filtered >> 1;
    } else {
        b[2 * x + 1] = temp_val;
    }
}
}
