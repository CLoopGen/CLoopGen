#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_pos = pos;  // Eliminate loop-carried dependency on 'pos' by using a local copy
    for (i = (((20 + 1) + 7) + 1); i <= ((((20 + 1) + 7) + 1) + 7); i++) {
        reg_alloc_order[local_pos++] = i;  // All writes are independent across iterations due to precomputed index
    }
    pos = local_pos;  // Update shared 'pos' only once after loop (eliminates per-iteration WAW and WAR dependencies on 'pos')
}
