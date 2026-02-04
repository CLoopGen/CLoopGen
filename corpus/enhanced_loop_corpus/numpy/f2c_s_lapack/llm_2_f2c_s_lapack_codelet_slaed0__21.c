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
    // Variant 1: Consecutive memory access pattern using stride transformation
    // Instead of accessing j*2 and (j<<1)-1, we reverse the loop and write to consecutive locations
    integer base = subpbs * 2;
    for (j = subpbs; j >= 1; --j) {
        integer val = iwork[j];
        iwork[base] = (val + 1) / 2;
        iwork[base - 1] = val / 2;
        base -= 2;
    }
}
