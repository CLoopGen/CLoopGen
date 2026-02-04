#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t len;
extern int k;
extern int16_t *tmp1;
extern int16_t *tmp2;
extern int16_t *tmp3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp_val;
    for (k = 0; k < len; k++) {
        temp_val = (*tmp1) + (*tmp2);
        tmp1--;
        tmp2--;
        tmp3[0] = temp_val;
        tmp3++;
    }
}
