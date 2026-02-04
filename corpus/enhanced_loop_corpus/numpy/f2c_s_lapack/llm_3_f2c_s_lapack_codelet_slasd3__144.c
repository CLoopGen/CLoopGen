#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt2;
extern integer vt2_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Stride
    // Introduce a fixed stride (e.g., every second element) across the array
    // This changes access pattern from dense to strided, skipping elements
    integer stride = 2;
    integer low = nlp2;
    integer high = i__1;
    for (i__ = low; i__ <= high; i__ += stride) {
        vt2[ktemp + i__ * vt2_dim1] = vt2[i__ * vt2_dim1 + 1];
    }
}
