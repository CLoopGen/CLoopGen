#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // Processes every second element in two passes to cover all indices
    for (i = 0; i < ni; i += 2)
        left[i] = q[i];
    for (i = 1; i < ni; i += 2)
        left[i] = q[i];
}
