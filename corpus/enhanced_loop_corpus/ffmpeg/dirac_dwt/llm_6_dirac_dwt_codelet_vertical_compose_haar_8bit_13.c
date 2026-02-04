#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int temp_b1 = b1[i];
    int temp_result = (int)(temp_b1 + 1U) >> 1;
    b0[i] = b0[i] - temp_result;
    b1[i] = temp_b1 + b0[i];
}
}
