#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 1; i <= 8; i++, LARp += 2, LARpp_j += 2)
        *LARp = *LARpp_j;
}
