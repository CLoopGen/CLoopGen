#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased trip count with simplified access and minimal operations
    int step = 4;
    for (i = old_max_uid; i >= 0; i -= step)
        regmove_bb_head[i] = -1;
}
