#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with offset adjustment
    // Instead of accessing drp[-120+k] and drp[-80+k], we shift the base pointer
    // to make indexing non-negative and consecutive.
    word *base = drp - 120;
    for (k = 0; k <= 119; k++)
        base[k] = base[k + 40];
}
