#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t impulse_r[60];
extern int16_t temp_corr[60];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 30; i++) {
    temp_corr[i] = impulse_r[i] >> 1;
    temp_corr[i + 30] = impulse_r[i + 30] >> 1;
}
}
