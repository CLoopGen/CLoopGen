#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 63; i++) {
    int weight_left = 64 - (i + 1);
    int weight_right = i + 1;
    if (weight_left > weight_right)
        left[i] = (weight_left * left[-1] + weight_right * left[63] + 32) >> 6;
    else
        left[i] = (weight_right * left[-1] + weight_left * left[63] + 32) >> 6;
}
}
