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
for (i = 1; i <= 7; i += 2) {
    T[i] = T[i - 1] * t;
    if (i + 1 <= 7) {
        T[i + 1] = T[i] * t;
    }
    H[i] = H[i - 1] * (t * f);
    if (i + 1 <= 7) {
        H[i + 1] = H[i] * (t * f);
    }
}
}
