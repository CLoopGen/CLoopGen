#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern using a forward loop
    // Reverses the original direction and accesses elements in increasing order
    // Maintains similar data dependency but improves spatial locality
    for (j = 3; j <= 31; j += 2)
        tab[j] += tab[j - 2];
}
