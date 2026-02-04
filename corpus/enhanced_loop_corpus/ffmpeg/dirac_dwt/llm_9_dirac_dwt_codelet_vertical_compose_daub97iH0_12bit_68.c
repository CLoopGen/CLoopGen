#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int32_t sum = b0[i] + (unsigned int)b2[i];
    int32_t scaled = (6497 * sum + 2048) >> 12;
    b1[i] = (unsigned int)(b1[i]) + scaled;
    b1[i] = (b1[i] > 0) ? (b1[i] + 1) : b1[i]; // Additional arithmetic to increase computational intensity
}
}
