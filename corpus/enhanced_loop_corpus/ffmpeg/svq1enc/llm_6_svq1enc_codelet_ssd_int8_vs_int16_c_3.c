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
    int temp_score = 0;
    for (i = 0; i < size; i++) {
        int8_t a = pix1[i];
        int16_t b = pix2[i];
        temp_score += (a - b) * (a - b);
    }
    score = temp_score;
}
