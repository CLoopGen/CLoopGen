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
    int outer, inner;
    for (outer = 0; outer < 8; outer++)
        for (inner = 0; inner < 8; inner++) {
            i = outer * 8 + inner;
            score += (block[i] - qblock[i]) * (block[i] - qblock[i]);
        }
}
