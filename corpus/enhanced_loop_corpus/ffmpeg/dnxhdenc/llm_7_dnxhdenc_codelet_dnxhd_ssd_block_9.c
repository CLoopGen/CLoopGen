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
    int16_t prev_block = 0;
    for (i = 0; i < 64; i++) {
        int16_t current_diff = (block[i] - qblock[i]);
        score += current_diff * current_diff;
        prev_block = block[i]; 
    }
}
