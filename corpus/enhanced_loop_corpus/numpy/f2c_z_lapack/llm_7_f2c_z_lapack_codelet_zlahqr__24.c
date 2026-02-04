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
integer prev_index1 = 0, prev_index2 = 0;
for (j = *ilo; j <= i__1; ++j) {
    integer index1 = j + 2 + j * h_dim1;
    integer index2 = j + 3 + j * h_dim1;
    h__[index1].r = (j == *ilo) ? 0. : h__[prev_index1].r;
    h__[index1].i = 0.;
    h__[index2].r = (j == *ilo) ? 0. : h__[prev_index2].r;
    h__[index2].i = 0.;
    prev_index1 = index1;
    prev_index2 = index2;
}
}
