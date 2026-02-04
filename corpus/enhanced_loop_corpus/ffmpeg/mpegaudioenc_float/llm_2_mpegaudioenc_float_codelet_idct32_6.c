#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 4th element instead of every 2nd)
    for (j = 31; j >= 6; j -= 4)
        tab[j] += tab[j - 4];
}
