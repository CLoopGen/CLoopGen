#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < subframe_size + (143 + 8 + 1); i++) {
    int16_t val = residual[i];
    if (val >= 0) {
        tmp |= val;
    } else {
        tmp |= -val;
    }
}
}
