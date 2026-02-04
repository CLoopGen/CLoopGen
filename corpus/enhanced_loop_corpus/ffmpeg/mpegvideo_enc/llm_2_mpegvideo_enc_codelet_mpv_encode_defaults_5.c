#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t default_fcode_tab[8193];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = -16; i < 16; i += 2) {
        default_fcode_tab[i + 4096] = 1;
        if (i + 1 < 16) {
            default_fcode_tab[i + 1 + 4096] = 1;
        }
    }
}
