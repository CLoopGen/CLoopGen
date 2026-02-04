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
    score = 0;
    for (i = 0; i < size; i++) {
        int8_t diff8 = pix1[i];
        int16_t diff16 = pix2[i];
        int16_t diff = diff8 - diff16;
        if (diff != 0) {
            score += diff * diff;
        }
    }
}
