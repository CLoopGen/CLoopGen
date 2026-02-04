#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 7; i < 16; i += 2) {
        is_table[0][i] = 0.;
        is_table[1][i] = 0.;
        if (i + 1 < 16) {
            is_table[0][i + 1] = 0.;
            is_table[1][i + 1] = 0.;
        }
    }
}
