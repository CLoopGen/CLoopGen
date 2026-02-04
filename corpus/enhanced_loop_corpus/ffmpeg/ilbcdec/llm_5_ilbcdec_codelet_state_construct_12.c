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
for (k = 0; k < len && tmp2 >= &ilbc_state[0]; k++) {
    int16_t product = (int16_t)(maxVal) * (int16_t)(ilbc_state[(*tmp2)]);
    int32_t biased = ((int32_t)product) + 262144;
    (*tmp1) = (int16_t)(biased >> 19);
    tmp1++;
    tmp2--;
}
}
