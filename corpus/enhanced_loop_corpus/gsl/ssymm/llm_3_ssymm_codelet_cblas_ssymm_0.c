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
    // Variant 2: Consecutive memory access with pointer arithmetic - flatten the 2D access into a sequential scan
    float *ptr = C;
    int total_elements = n1 * n2;
    for (int idx = 0; idx < total_elements; idx++) {
        ptr[idx] = 0.;
    }
}
