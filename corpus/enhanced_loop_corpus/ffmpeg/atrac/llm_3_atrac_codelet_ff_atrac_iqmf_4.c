#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inlo;
extern float *inhi;
extern unsigned int nIn;
extern int i;
extern float *p3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed offsets
    // Simulate strided access by stepping through arrays with explicit index scaling
    float *inlo_ptr = inlo;
    float *inhi_ptr = inhi;
    float *out_ptr = p3;

    for (i = 0; i < nIn; i += 2) {
        out_ptr[0] = inlo_ptr[0] + inhi_ptr[0];
        out_ptr[1] = inlo_ptr[0] - inhi_ptr[0];
        out_ptr[2] = inlo_ptr[1] + inhi_ptr[1];
        out_ptr[3] = inlo_ptr[1] - inhi_ptr[1];

        inlo_ptr += 2;
        inhi_ptr += 2;
        out_ptr += 4;
    }
}
