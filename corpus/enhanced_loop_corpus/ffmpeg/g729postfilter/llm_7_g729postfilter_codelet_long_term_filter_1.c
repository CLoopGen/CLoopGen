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
    tmp = 0;
    for (i = 0; i < subframe_size + (143 + 8 + 1); i += 2) {
        int16_t val1 = residual[i];
        int16_t abs1 = (val1 >= 0) ? val1 : -val1;
        tmp |= abs1;

        if (i + 1 < subframe_size + (143 + 8 + 1)) {
            int16_t val2 = residual[i + 1];
            int16_t abs2 = (val2 >= 0) ? val2 : -val2;
            tmp |= abs2;
        }
    }
}
