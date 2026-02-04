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
int outer_k;
for (outer_k = 1; outer_k <= 8; outer_k += 2) {
    k = outer_k;
    Ag += lanczos_7_c[k] / (x + k);
    if (k + 1 <= 8) {
        k = outer_k + 1;
        Ag += lanczos_7_c[k] / (x + k);
    }
}
}
