#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;
extern INT n1;
extern INT is1;
extern INT os1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use base pointers advanced by fixed strides per outer loop iteration to simulate irregular access
    R *base_I = I;
    R *base_O = O;
    for (i1 = 0; i1 < n1; ++i1) {
        R *ptr_I = base_I;
        R *ptr_O = base_O;
        for (i0 = 0; i0 < n0; ++i0) {
            R x0 = ptr_I[0];
            R x1 = ptr_I[1];
            ptr_O[0] = x0;
            ptr_O[1] = x1;
            ptr_I += is0;
            ptr_O += os0;
        }
        base_I += is1;
        base_O += os1;
    }
}
