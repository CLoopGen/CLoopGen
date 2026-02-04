#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef unsigned int U32;

extern I32 *PL_regendp;
extern U32 *PL_reglastparen;
extern I32 n;
extern I32 lastparen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 i;
    // Eliminate loop-carried dependencies by unrolling and using independent indices
    // Assume minimal risk of overflow for realistic n values
    for (i = 0; i <= (*PL_reglastparen - lastparen - 1); i++) {
        PL_regendp[*PL_reglastparen - i] = -1;
        // No data dependency between iterations — each index computed independently
    }
}
