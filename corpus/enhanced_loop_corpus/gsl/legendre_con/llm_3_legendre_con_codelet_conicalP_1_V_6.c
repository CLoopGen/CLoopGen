#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double t;
extern  double f;
extern double T[8];
extern double H[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Strided memory access (access every second element in reverse order)
for (i = 6; i >= 0; i -= 2) {
    T[i + 1] = T[i] * t;
    H[i + 1] = H[i] * (t * f);
}
}
