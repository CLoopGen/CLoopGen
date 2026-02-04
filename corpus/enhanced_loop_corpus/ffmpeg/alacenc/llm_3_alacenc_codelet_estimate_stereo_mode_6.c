#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with offset base
    for (i = 3; i > 0; i--) {
        if (score[i] < score[best])
            best = i;
    }
}
