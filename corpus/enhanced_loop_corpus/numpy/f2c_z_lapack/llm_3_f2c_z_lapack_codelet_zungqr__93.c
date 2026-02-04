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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided access with reversed loop order
    // Change iteration order to reverse traversal (from high to low) and use fixed stride
    // This alters cache access pattern and may help in certain vectorization scenarios.

    integer idx;

    for (j = i__1; j >= kk + 1; --j) {  // Reverse outer loop
        for (i__ = kk; i__ >= 1; --i__) {  // Reverse inner loop
            idx = i__ + j * a_dim1;       // Original index computation
            a[idx].r = 0.0;
            a[idx].i = 0.0;
        }
    }
}
