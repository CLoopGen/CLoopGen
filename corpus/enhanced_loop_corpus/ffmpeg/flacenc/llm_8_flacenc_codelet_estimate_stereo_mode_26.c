#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 4; i += 2) {
        if (score[i] < score[best]) {
            best = i;
        }
        // Add extra arithmetic to increase computational intensity
        score[i] += (score[i] >> 1) + 1;
    }
}
