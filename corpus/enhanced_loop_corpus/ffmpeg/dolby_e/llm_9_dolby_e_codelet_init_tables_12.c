#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 13; i++) {
    int shift = 1 << i;
    float val1 = 1.F / shift;
    float val2 = 0.70710678118654757F / shift;
    exponent_tab[i * 4] = val1;
    exponent_tab[i * 4 + 1] = val2;
    if (i * 4 + 2 < 50) exponent_tab[i * 4 + 2] = val1 * 0.5F;
    if (i * 4 + 3 < 50) exponent_tab[i * 4 + 3] = val2 * 0.5F;
}
}
