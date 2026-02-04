#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t ms;
extern int *tc;
extern  int tc_divs[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of 1, but backwards)
    for (i = 2; i >= 0; i--) {
        tc[i] = ms % tc_divs[i];
        ms /= tc_divs[i];
    }
}
