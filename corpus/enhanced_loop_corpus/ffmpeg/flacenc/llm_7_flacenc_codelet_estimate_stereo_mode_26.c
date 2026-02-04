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
    uint64_t local_score[4];
    for (i = 0; i < 4; i++) {
        local_score[i] = score[i];
    }
    for (i = 1; i < 4; i++) {
        if (local_score[i] < local_score[local_best]) {
            local_best = i;
        }
    }
    best = local_best;
}
