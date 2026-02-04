#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        C[ldc * i + j] = 0.;
    }
    // Additional inner operation to simulate increased depth without adding loops
    if (i % 2 == 0 && i > 0) {
        C[ldc * i - 1] = 1.0;
    }
}
}
