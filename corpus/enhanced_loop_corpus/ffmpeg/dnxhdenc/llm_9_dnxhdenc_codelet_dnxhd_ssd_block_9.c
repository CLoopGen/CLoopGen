#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *qblock;
extern int16_t *block;
extern int score;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    score = 0;
    for (i = 0; i < 32; i++) {
        int idx1 = i;
        int idx2 = 63 - i;
        int diff1 = block[idx1] - qblock[idx1];
        int diff2 = block[idx2] - qblock[idx2];
        score += diff1 * diff1;
        score += diff2 * diff2;
    }
}
