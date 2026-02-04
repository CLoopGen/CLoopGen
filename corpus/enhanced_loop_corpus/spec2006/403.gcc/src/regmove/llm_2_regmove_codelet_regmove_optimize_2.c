#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = old_max_uid; i >= 0; i -= 2)
        regmove_bb_head[i] = -1;
}
