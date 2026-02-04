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
    I32 temp_start_val = *PL_reglastparen + 1;
    for (paren = temp_start_val; (I32)paren <= PL_regnpar; paren++) {
        U32 next_paren = paren + 1;
        if ((I32)next_paren <= PL_regnpar) {
            PL_regstartp[next_paren] = -1;
        }
        PL_regendp[paren] = -1;
    }
}
