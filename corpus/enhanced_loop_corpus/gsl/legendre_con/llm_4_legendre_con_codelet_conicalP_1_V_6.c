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
// Variant 2: Consecutive forward access with offset base (shifted index range using consecutive pattern)
int j;
for (j = 0; j < 7; j++) {
    int idx = j + 1;
    T[idx] = T[idx - 1] * t;
    H[idx] = H[idx - 1] * (t * f);
}
}
