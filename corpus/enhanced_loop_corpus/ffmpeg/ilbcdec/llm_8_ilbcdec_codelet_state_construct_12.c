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
for (k = 0; k < len * 2; k += 2) {
    int32_t product1 = ((int32_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)]));
    int32_t rounded_val1 = product1 + 262144;
    (*tmp1) = (int16_t)(rounded_val1 >> 19);
    tmp1++;
    tmp2--;

    if (k + 1 < len * 2) {
        int32_t product2 = ((int32_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)]));
        int32_t rounded_val2 = product2 + 262144;
        (*tmp1) = (int16_t)(rounded_val2 >> 19);
        tmp1++;
        tmp2--;
    }
}
}
