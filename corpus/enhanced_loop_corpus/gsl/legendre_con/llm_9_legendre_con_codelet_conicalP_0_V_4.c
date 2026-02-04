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
for (i = 1; i <= 6; i++) {
    T[i]   = T[i - 1] * t;
    T[i+1] = T[i] * t * t;
    H[i]   = H[i - 1] * (t * f);
    H[i+1] = H[i] * (t * f) * (t * f);
}
}
