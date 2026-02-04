#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int temp1 = 9U * b1[i];
    int temp2 = 9U * b3[i];
    int temp_sum = temp1 + temp2 - b4[i] - b0[i] + 8;
    int shift_val = temp_sum >> 4;
    b2[i] = (int)(((unsigned int)(b2[i]) + shift_val));
}
}
