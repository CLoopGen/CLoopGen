#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int pitch_lag;
extern int16_t vector[60];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = pitch_lag; i < 60; i += pitch_lag) {
    int16_t temp_sum = 0;
    for (j = 0; j < 60 - i; j++) {
        temp_sum += vector[j];
        buf[i + j] += temp_sum;
    }
}
}
