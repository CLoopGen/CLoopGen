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
    double temp_t = T[i - 1] * t;
    double temp_h = H[i - 1] * (t * f);
    T[i] = temp_t;
    H[i] = temp_h;
    T[i+1] = temp_t * t;
    H[i+1] = temp_h * (t * f);
}
}
