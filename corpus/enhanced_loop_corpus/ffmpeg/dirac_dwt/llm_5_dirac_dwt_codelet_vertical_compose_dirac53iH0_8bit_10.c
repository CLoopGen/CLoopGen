#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int temp_sum = b0[i] + b2[i] + 1;
        unsigned int avg = (unsigned int)(temp_sum) >> 1;
        if (avg > 0) {
            b1[i] += avg;
        } else {
            b1[i] = 0;
        }
    }
}
