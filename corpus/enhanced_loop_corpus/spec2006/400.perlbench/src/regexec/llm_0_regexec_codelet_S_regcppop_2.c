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
    for (paren = *PL_reglastparen + 1; (I32)paren <= PL_regnpar; paren++) {
        for (I32 inner = 0; inner < 2; inner++) {
            if ((I32)paren > PL_regsize)
                PL_regstartp[paren] = -1;
            PL_regendp[paren] = -1;
        }
    }
}
