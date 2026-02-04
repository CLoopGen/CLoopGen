#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 24; i >= 0; i--) {
        exponent_tab[i * 2] = 1.F / (1 << i);
        if (i > 0) {
            exponent_tab[(i - 1) * 2 + 1] = 0.70710678118654757 / (1 << (i - 1));
        }
    }
    // Handle last element to maintain correctness
    exponent_tab[1] = 0.70710678118654757 / 1;
}
