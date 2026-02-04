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
    int factor = (size > 100) ? 1 : (size > 10) ? 2 : 4;
    for (i = 0; i < size; i++) {
        int8_t  d1 = pix1[i];
        int16_t d2 = pix2[i];
        int32_t diff = (int32_t)(d1 - d2);
        score += diff * diff;
        score += (diff > 0) ? 1 : -1; // Additional light computation to increase intensity
    }
}
