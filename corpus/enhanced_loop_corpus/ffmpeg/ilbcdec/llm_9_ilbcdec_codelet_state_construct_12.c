#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ilbc_state[8];
extern int16_t len;
extern int k;
extern int16_t maxVal;
extern int16_t *tmp1;
extern int16_t *tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < len; k++) {
    int32_t scaled_maxVal = (int32_t)(maxVal) << 5; 
    int32_t index_val = (int32_t)(ilbc_state[(*tmp2)]);
    int32_t product = scaled_maxVal * index_val; 
    int32_t adjusted = product + (1 << 14); 
    (*tmp1) = (int16_t)((adjusted) >> 14); 
    tmp1++;
    tmp2--;
}
}
