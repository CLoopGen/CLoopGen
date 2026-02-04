#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 4; i++) {
        best = (score[i] < score[best]) ? i : best;
    }
}
