#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (int pe = 0; pe < npes; pe += 2)
        step[pe] = 0;
    // Handle odd-sized npes by ensuring the last element is set if needed
    if (npes > 0 && npes % 2 == 1)
        step[npes - 1] = 0;
}
