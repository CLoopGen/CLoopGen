#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t impulse_r[60];
extern int16_t temp_corr[60];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 60; i += 3) {
    temp_corr[i] = (impulse_r[i] + impulse_r[i] + impulse_r[i]) >> 2;
    if (i + 1 < 60) temp_corr[i + 1] = (impulse_r[i + 1] + impulse_r[i + 1] + impulse_r[i + 1]) >> 2;
    if (i + 2 < 60) temp_corr[i + 2] = (impulse_r[i + 2] + impulse_r[i + 2] + impulse_r[i + 2]) >> 2;
}
}
