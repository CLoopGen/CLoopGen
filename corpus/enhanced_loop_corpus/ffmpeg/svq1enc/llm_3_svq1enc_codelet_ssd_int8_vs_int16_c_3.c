#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t *pix1;
extern  int16_t *pix2;
extern intptr_t size;
extern int score;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to beginning
    for (i = size - 1; i >= 0; i--)
        score += (pix1[i] - pix2[i]) * (pix1[i] - pix2[i]);
}
