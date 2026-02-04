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
    for (i = 1; i <= 7; i++) {
        T[i] = T[i - 1] * t;
        if (i > 4) {
            H[i] = H[i - 1] * (t * f);
        } else {
            H[i] = H[i - 1];
        }
    }
}
