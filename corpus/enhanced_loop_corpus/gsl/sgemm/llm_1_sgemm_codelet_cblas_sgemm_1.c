#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j, k;
    for (k = 0; k < n1 * n2; k++) {
        i = k;
        if (i >= n1) continue;
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] *= beta;
            break; // Ensures inner loop runs only once per outer iteration
        }
    }
}
