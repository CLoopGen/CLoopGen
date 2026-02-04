#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double x;
extern int k;
extern double Ag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (k = 1; k <= 4; k++) {
        temp += lanczos_7_c[k] * (x + k);
    }
    Ag += temp / (x + 1.0);
}
