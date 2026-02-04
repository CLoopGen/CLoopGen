#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern by removing strided jumps and adjusting dependencies
    for (j = 31; j >= 3; j--)
        tab[j] += tab[j - 1];
}
