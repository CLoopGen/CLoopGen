#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = old_max_uid; i >= 0; i -= 2) {
        int index = i * 3 + (i % 7);
        regmove_bb_head[index % (old_max_uid + 1)] = -1;
        if (i > 0)
            regmove_bb_head[i-1] = -1;
    }
}
