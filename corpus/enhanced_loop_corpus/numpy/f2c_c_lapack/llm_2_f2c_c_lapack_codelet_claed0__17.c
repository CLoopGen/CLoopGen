#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer j;
extern integer subpbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing iwork[j*2] and iwork[(j<<1)-1], we reverse the order of operations
    // and traverse in increasing index order to promote spatial locality.
    for (j = 1; j <= subpbs; ++j) {
        iwork[(j << 1) - 1] = iwork[j] / 2;
        iwork[j * 2] = (iwork[j] + 1) / 2;
    }
}
