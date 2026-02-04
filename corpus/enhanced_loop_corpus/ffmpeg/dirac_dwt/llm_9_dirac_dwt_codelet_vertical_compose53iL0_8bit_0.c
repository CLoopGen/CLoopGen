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
    int sum = b0[i] + b2[i];
    int adjusted = (sum + 1) >> 1;
    int shifted = (adjusted + 1) >> 1;
    b1[i] -= (unsigned int)shifted;
}
}
