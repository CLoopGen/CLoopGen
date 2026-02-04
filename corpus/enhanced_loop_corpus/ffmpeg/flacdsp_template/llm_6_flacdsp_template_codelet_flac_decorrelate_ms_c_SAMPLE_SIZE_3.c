#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int32_t temp1 = in[0][i];
        int32_t temp2 = in[1][i];
        unsigned int a = temp1;
        int b = temp2;
        a -= b >> 1;
        // Introduce artificial WAW and WAR dependencies by reordering
        // and using temporary variables with delayed write-back.
        int16_t val1 = (int16_t)((a + b) << shift);
        int16_t val2 = (int16_t)(a << shift);
        // Enforce dependency chain: val2 depends on val1 computation
        (*samples++) = val1;
        (*samples++) = val2;
    }
}
