#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int best;
extern uint64_t score[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of -1)
    for (i = 3; i >= 1; i--)
        if (score[i] < score[best])
            best = i;
}
