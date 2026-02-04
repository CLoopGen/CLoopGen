#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int indices[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (k = 0; k < 9; k++) {
        L_ACF[indices[k]] <<= 1;
    }
}
