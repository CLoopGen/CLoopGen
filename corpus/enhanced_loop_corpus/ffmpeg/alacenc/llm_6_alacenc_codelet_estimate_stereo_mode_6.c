#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_best = best;
    for (i = 1; i < 4; i++) {
        uint64_t current_score = score[i];
        uint64_t best_score = score[temp_best];
        if (current_score < best_score) {
            temp_best = i;
        }
    }
    best = temp_best;
}
