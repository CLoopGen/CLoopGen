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
    // Variant 1: Strided memory access (stride of 2)
    I32 start = *PL_reglastparen;
    for (n = (start % 2 == 0) ? start : start - 1; n > lastparen; n -= 2)
        PL_regendp[n] = -1;
}
