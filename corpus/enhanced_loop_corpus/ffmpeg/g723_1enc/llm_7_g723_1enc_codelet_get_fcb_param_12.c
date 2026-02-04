#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t impulse_r[60];
extern int16_t temp_corr[60];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 60; i += 2) {
        temp_corr[i] = impulse_r[i] >> 1;
        if (i + 1 < 60)
            temp_corr[i + 1] = temp_corr[i] >> 1; // Introduces WAW and RAW dependency: temp_corr[i+1] depends on temp_corr[i]
    }
}
