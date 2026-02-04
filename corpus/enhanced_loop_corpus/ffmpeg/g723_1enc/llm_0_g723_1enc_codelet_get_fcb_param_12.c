#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t impulse_r[60];
extern int16_t temp_corr[60];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 60; i++) {
    for (j = 0; j < 1; j++) {
        temp_corr[i] = impulse_r[i] >> 1;
    }
}
}
