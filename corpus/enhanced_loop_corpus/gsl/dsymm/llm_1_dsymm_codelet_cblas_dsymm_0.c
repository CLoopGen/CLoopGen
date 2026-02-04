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
for (i = 0; i < n1 && j < n2; i++) {
    C[ldc * i + j] = 0.;
    j++;
    if (j >= n2) {
        j = 0;
    }
}
}
