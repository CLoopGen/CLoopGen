#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    uint8_t temp1 = (left[-1] + left[63]) >> 1;
    uint8_t temp2 = (left[-1] * 3 + left[63]) >> 2;
    left[i*2]     = (temp1 + 16) >> 5;
    left[i*2+1]   = (temp2 + 16) >> 5;
}
}
