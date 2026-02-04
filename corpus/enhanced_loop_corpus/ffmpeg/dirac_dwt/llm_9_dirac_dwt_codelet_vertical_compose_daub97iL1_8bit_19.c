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
    int16_t sum = b0[i] + b2[i];
    int temp1 = (1817 * sum + 2048) >> 12;
    int temp2 = (unsigned int)(b1[i]) - temp1;
    b1[i] = (int16_t)temp2;
}
}
