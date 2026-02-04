#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < 64; i += 2) {
        int16_t val = temp[i];
        int abs_val = (val >= 0) ? val : -val;
        sum = (sum > abs_val) ? sum : abs_val;
    }
}
