#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse-order memory access
    // Iterates from the end of the array to the beginning
    for (i = order - 1; i >= 0; i--)
        res[i] = smp[i];
}
