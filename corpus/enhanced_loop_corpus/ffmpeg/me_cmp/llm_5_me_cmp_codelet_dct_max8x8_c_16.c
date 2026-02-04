#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 64; ++i) {
        int16_t abs_val = temp[i];
        abs_val = (abs_val ^ (abs_val >> 15)) - (abs_val >> 15); // Fast absolute value using bit manipulation
        if (i == 0 || abs_val > sum) {
            sum = abs_val;
        }
    }
}
