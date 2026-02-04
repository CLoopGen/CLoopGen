#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t impulse_r[60];
extern int16_t temp_corr[60];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = 59; i >= 0; i--)
        temp_corr[i] = impulse_r[i] >> 1;
}
