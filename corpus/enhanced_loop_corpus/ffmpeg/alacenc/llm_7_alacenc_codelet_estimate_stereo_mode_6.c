#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_best = best;
    uint64_t min_score = score[best];
    for (i = 1; i < 4; i++) {
        uint64_t s = score[i];
        int smaller = s < min_score;
        local_best = smaller ? i : local_best;
        min_score = smaller ? s : min_score;
    }
    best = local_best;
}
