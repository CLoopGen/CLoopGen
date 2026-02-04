#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 50; i += 2) {
    float inv_shift = 1.F / (1 << (i / 2));
    exponent_tab[i] = inv_shift;
    exponent_tab[i + 1] = 0.70710678118654757F * inv_shift;
}
}
