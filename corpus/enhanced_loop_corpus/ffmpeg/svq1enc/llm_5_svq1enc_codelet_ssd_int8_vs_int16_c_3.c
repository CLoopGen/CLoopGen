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
        int16_t val1 = (int16_t)pix1[i];
        int16_t val2 = pix2[i];
        int16_t diff = val1 - val2;
        int16_t abs_diff = diff >= 0 ? diff : -diff;
        if (abs_diff > 1) {
            score += abs_diff * abs_diff;
        } else {
            score += abs_diff;
        }
    }
}
