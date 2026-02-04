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
for (k = 1; k <= 8; k++) {
    if (lanczos_7_c[k] != 0.0) {
        Ag += lanczos_7_c[k] / (x + k);
    }
}
}
