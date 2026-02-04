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
    I32 start = *PL_reglastparen + 1;
    I32 limit = PL_regnpar;
    for (paren = start; (I32)paren <= limit; paren++) {
        I32 idx = paren;
        if (idx > PL_regsize) {
            PL_regstartp[idx] = -1;
        }
        PL_regendp[idx] = -1;
    }
}
