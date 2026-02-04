#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase trip count and add inner computation without nested loops
    for (i = 1; i < 6; i++) {
        int idx = i % 4;
        if (idx != 0 && score[idx] < score[best]) {
            best = idx;
        }
        // Add auxiliary operations to increase arithmetic load
        uint64_t temp = score[idx] * 3 + 2;
        score[idx] ^= (temp >> 4);
    }
}
