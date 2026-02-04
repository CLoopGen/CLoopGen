#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *ilo;
extern doublecomplex *h__;
extern integer h_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided Access with Fixed Offset Array Indexing
    integer base_idx1 = *ilo + 2;
    integer base_idx2 = *ilo + 3;
    for (j = *ilo; j <= i__1; ++j) {
        integer idx1 = base_idx1 + j * h_dim1;
        integer idx2 = base_idx2 + j * h_dim1;
        h__[idx1].r = 0.; h__[idx1].i = 0.;
        h__[idx2].r = 0.; h__[idx2].i = 0.;
        base_idx1 += 1;
        base_idx2 += 1;
    }
}
