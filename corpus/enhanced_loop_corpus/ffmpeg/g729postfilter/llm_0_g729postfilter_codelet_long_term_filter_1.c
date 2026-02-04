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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < subframe_size + (143 + 8 + 1); i++)
            tmp |= ((residual[i]) >= 0 ? (residual[i]) : (-(residual[i])));
    }
}
