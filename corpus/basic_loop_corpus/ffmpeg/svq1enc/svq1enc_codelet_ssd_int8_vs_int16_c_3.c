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
for (i = 0; i < size; i++)
    score += (pix1[i] - pix2[i]) * (pix1[i] - pix2[i]);

}
