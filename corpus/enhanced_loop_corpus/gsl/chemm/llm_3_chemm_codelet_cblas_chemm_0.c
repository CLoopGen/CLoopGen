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
    // Variant 2: Strided memory access with reversed loop order to emphasize column-major traversal
    float *C_ptr = (float *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int offset = 2 * (ldc * i + j);
            C_ptr[offset] = 0.;
            C_ptr[offset + 1] = 0.;
        }
    }
}
