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
    int local_score = score;
    for (i = 0; i < size; i += 2) {
        int diff1 = 0, diff2 = 0;
        if (i < size) {
            diff1 = pix1[i] - pix2[i];
        }
        if (i + 1 < size) {
            diff2 = pix1[i+1] - pix2[i+1];
        }
        local_score += diff1 * diff1 + diff2 * diff2;
    }
    score = local_score;
}
