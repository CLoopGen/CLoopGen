#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25; i++) {
        float scale = (i < 10) ? (1.F / (1 << i)) : (1.F / (1 << (i - 5)));
        exponent_tab[i * 2] = scale;
        exponent_tab[i * 2 + 1] = 0.70710678118654757 * scale;
    }
}
