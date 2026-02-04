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
    int j;
    for (i = 0; i < subframe_size + 152; i += 2) {
        int16_t val1 = residual[i];
        int16_t abs_val1 = (val1 >= 0) ? val1 : -val1;
        tmp |= abs_val1;
        if (i + 1 < subframe_size + 152) {
            int16_t val2 = residual[i + 1];
            int16_t abs_val2 = (val2 >= 0) ? val2 : -val2;
            tmp |= abs_val2;
        }
    }
}
