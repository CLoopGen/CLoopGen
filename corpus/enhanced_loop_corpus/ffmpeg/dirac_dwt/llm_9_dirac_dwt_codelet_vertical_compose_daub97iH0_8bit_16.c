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
int scale_factor = 3;
for (i = 0; i < width * scale_factor; i++) {
    int idx = i % width;
    int temp = (b0[idx] + (unsigned int)b2[idx]);
    temp = 6497 * temp + 2048;
    temp >>= 12;
    b1[idx] = ((unsigned int)(b1[idx]) + (int)temp);
}
}
