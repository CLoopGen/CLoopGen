#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i += 2) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] = 0.;
            C[ldc * (i + 1) + j] = 0.;
        }
    } else {
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] = 0.;
        }
    }
}
}
