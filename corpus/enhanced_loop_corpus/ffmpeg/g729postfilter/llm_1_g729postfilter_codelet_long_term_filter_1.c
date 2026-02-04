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
    for (i = 0; i < subframe_size + (143 + 8 + 1); i += 2) {
        tmp |= ((residual[i]) >= 0 ? (residual[i]) : (-(residual[i])));
        if (i + 1 < subframe_size + (143 + 8 + 1)) {
            tmp |= ((residual[i + 1]) >= 0 ? (residual[i + 1]) : (-(residual[i + 1])));
        }
    }
}
