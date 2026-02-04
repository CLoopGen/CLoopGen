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
    // Variant 2: Strided memory access with a fixed stride over flattened index, processing every ldc-th element
    int idx;
    for (idx = 0; idx < n1 * n2; idx += n2) {
        for (j = 0; j < n2; j++) {
            C[idx + j] = 0.0f;
        }
    }
}
