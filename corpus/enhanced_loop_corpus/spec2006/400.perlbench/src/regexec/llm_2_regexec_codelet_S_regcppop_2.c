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
    // Variant 1: Consecutive memory access using pointer arithmetic for better locality
    I32 start = *PL_reglastparen + 1;
    I32 limit = PL_regnpar;
    I32 *startp_base = PL_regstartp + start;
    I32 *endp_base = PL_regendp + start;

    for (paren = start; (I32)paren <= limit; paren++) {
        if ((I32)paren > PL_regsize) {
            *startp_base = -1;
        }
        *endp_base = -1;
        startp_base++;
        endp_base++;
    }
}
