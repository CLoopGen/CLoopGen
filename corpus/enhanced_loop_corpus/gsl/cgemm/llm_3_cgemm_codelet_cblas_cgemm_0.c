#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order to change traversal pattern
    float *C_ptr = (float *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int index = ldc * i + j;
            C_ptr[2 * index] = 0.;
            C_ptr[2 * index + 1] = 0.;
        }
    }
}
