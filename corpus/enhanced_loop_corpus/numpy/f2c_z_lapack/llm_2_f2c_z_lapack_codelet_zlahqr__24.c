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
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    doublecomplex *h_ptr = &h__[*ilo + 2 + *ilo * h_dim1];
    integer j_size = h_dim1 * sizeof(doublecomplex);
    for (j = *ilo; j <= i__1; ++j) {
        h_ptr->r = 0.; h_ptr->i = 0.;
        (h_ptr + 1)->r = 0.; (h_ptr + 1)->i = 0.;
        h_ptr = (doublecomplex*)((char*)h_ptr + j_size + sizeof(doublecomplex));
    }
}
