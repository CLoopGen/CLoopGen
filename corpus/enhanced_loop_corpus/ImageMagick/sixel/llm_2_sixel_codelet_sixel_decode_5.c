#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4
    for (int i = 0; i < 1024; i += 4) {
        sixel_palet[i] = ((int)(((ssize_t)((255) & 255) << 16) + (((255) & 255) << 8) + ((255) & 255)));
    }
}
