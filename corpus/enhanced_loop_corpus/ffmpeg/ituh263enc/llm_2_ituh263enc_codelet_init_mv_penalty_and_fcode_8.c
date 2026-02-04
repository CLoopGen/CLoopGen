#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t umv_fcode_tab[8193];
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (mv = 0; mv < 4096 * 2 + 1; mv += 2) {
        umv_fcode_tab[mv] = 1;
    }
    // Fill in the odd indices in a second pass to maintain correctness
    for (mv = 1; mv < 4096 * 2 + 1; mv += 2) {
        umv_fcode_tab[mv] = 1;
    }
}
