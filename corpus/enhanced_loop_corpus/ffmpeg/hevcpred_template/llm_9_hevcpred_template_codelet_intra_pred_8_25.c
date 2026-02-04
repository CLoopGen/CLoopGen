#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        uint8_t temp1 = left[-1] + 1;
        uint8_t temp2 = left[63] - 1;
        left[i*2]     = ((64 - i) * temp1 + i * temp2 + 16) >> 5;
        if (i < 31) left[i*2+1] = ((63 - i) * temp1 + (i+1) * temp2 + 16) >> 5;
    }
}
