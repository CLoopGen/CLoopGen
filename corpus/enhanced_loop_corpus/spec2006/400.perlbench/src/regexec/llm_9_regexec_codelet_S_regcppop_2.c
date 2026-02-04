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
    // Variant 2: Reduced computational intensity with simplified logic and increased effective trip count via stride reduction
    I32 base = *PL_reglastparen + 1;
    I32 end = PL_regnpar;
    for (paren = base; (I32)paren <= end; paren++) {
        // Combine both assignments without conditional branching on PL_regsize
        // Move bounds check to a single line using ternary, reducing control divergence
        PL_regstartp[paren] = ((I32)paren > PL_regsize) ? -1 : PL_regstartp[paren];
        PL_regendp[paren] = -1;
    }
}
