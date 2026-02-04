#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef unsigned int U32;

extern I32 PL_regnpar;
extern I32 PL_regsize;
extern I32 *PL_regstartp;
extern I32 *PL_regendp;
extern U32 *PL_reglastparen;
extern U32 paren;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    I32 start = *PL_reglastparen + 1;
    I32 limit = PL_regnpar;
    for (paren = start; (I32)paren <= limit; paren += 2) {
        if ((I32)paren > PL_regsize)
            PL_regstartp[paren] = -1;
        PL_regendp[paren] = -1;

        // Unroll next iteration if within bounds
        if ((I32)paren + 1 <= limit) {
            if ((I32)paren + 1 > PL_regsize)
                PL_regstartp[paren + 1] = -1;
            PL_regendp[paren + 1] = -1;
        }
    }
}
