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
    int temp_sum = b0[i] + b2[i] + 2;
    int shifted = temp_sum >> 2;
    b1[i] = (b1[i] + (unsigned int)((int)(shifted + b1[i]) >> 1));
}
}
