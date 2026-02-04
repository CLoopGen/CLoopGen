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
    int temp_score = 0;
    for (i = 0; i < 64; i += 2) {
        int diff1 = block[i] - qblock[i];
        int diff2 = block[i + 1] - qblock[i + 1];
        temp_score += diff1 * diff1 + diff2 * diff2;
    }
    score += temp_score;
}
