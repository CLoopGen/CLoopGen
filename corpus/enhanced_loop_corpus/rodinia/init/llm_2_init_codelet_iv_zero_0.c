#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *ix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < ix->dim; i += 2)
        ix->ive[i] = 0;
    // Handle odd-sized dim by ensuring last element is set if needed
    if (ix->dim % 2 == 1) {
        ix->ive[ix->dim - 1] = 0;
    }
}
