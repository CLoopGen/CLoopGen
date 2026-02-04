#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every other element)
    // Simulates non-unit stride access, possibly modeling blocked or interleaved data structures
    integer start_idx = 2 + a_dim1;
    integer stride = 2; // Access every second element after the initial offset
    for (i__ = 0; i__ < (i__1 - 1 + stride - 1) / stride; ++i__) {
        integer actual_idx = start_idx + i__ * stride;
        a[actual_idx].r = 0.0;
        a[actual_idx].i = 0.0;
    }
}
