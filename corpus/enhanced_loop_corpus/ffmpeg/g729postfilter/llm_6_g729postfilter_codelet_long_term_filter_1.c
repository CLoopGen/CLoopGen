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
    int16_t local_tmp = 0;
    for (i = 0; i < subframe_size + (143 + 8 + 1); i++) {
        int16_t abs_val = (residual[i] >= 0) ? residual[i] : -residual[i];
        local_tmp |= abs_val;
    }
    tmp = local_tmp;
}
