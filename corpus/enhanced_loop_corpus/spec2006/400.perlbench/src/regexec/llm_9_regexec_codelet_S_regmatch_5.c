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
    // Variant 2: Reduced trip count by stepping in increments of 2, but with duplicated body to maintain coverage
    // Effectively reduces loop iterations by half while preserving access to all indices via unrolling
    I32 step = *PL_reglastparen - (*PL_reglastparen % 2);  // Make even to simplify unrolling
    for (n = step; n > lastparen; n -= 2) {
        PL_regendp[n] = -1;
        if (n-1 > lastparen) {
            PL_regendp[n-1] = -1;
        }
    }
    // Handle odd starting point if needed
    if ((*PL_reglastparen % 2) == 1 && *PL_reglastparen > lastparen) {
        PL_regendp[*PL_reglastparen] = -1;
    }
}
