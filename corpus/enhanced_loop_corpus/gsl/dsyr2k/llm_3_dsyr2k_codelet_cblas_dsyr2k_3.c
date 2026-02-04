#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using pointer arithmetic
    // Process elements in increasing address order to improve spatial locality
    double *ptr = C;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            *(ptr++) *= beta;
        }
        ptr += (ldc - i - 1); // Skip unused portion at the end of each row
    }
}
