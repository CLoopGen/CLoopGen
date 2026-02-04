#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array
    int indices[3] = {1, 2, 3};
    for (i = 0; i < 3; i++) {
        int idx = indices[i];
        if (score[idx] < score[best])
            best = idx;
    }
}
