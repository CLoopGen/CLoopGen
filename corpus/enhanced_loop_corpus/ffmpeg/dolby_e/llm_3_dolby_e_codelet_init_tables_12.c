#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access in reverse order with alternating write pattern
    for (i = 24; i >= 0; i--) {
        int idx_even = (24 - i) * 2;      // Forward strided even index
        int idx_odd  = (24 - i) * 2 + 1;  // Forward strided odd index
        float scale = 1.F / (1 << i);
        exponent_tab[idx_even] = scale;
        exponent_tab[idx_odd]  = 0.70710678118654757F * scale;
    }
}
