#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned int shift;
extern uint32_t *src32;
extern  uint32_t mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
    for (i = 0; i < len; i += 8) {
        temp0 = (src32[i] << shift) & mask;
        temp1 = (src32[i + 1] << shift) & mask;
        temp2 = (src32[i + 2] << shift) & mask;
        temp3 = (src32[i + 3] << shift) & mask;
        temp4 = (src32[i + 4] << shift) & mask;
        temp5 = (src32[i + 5] << shift) & mask;
        temp6 = (src32[i + 6] << shift) & mask;
        temp7 = (src32[i + 7] << shift) & mask;
        src32[i] = temp0;
        src32[i + 1] = temp1;
        src32[i + 2] = temp2;
        src32[i + 3] = temp3;
        src32[i + 4] = temp4;
        src32[i + 5] = temp5;
        src32[i + 6] = temp6;
        src32[i + 7] = temp7;
    }
}
