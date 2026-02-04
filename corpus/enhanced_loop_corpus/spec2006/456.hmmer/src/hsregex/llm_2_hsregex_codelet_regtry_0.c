#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed direction
    // Instead of decrementing loop index, we use increasing index but write in reverse order
    // We assume that stp and enp point to the beginning of allocated arrays of size 10
    char **temp_stp = stp + 9;
    char **temp_enp = enp + 9;
    for (i = 0; i < 10; i++) {
        *temp_stp-- = ((void *)0);
        *temp_enp-- = ((void *)0);
    }
}
