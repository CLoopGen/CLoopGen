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
    for (i = 0; i < 64; i++) {
        int16_t diff = block[i] - qblock[i];
        if (diff != 0) {
            score += diff * diff;
        }
    }
}
