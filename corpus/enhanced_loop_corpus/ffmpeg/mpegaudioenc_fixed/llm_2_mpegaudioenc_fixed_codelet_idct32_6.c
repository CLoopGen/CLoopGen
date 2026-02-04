#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 4th element instead of every 2nd)
    // The original loop accessed j and j-2 with step -2; now we use a larger stride pattern for memory access
    for (j = 31; j >= 6; j -= 4)
        tab[j] += tab[j - 6];
}
