#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *ilo;
extern singlecomplex *h__;
extern integer h_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_r = 0.F, temp_i = 0.F;
for (j = *ilo; j <= i__1; ++j) {
    singlecomplex *target1 = &h__[j + 2 + j * h_dim1];
    singlecomplex *target2 = &h__[j + 3 + j * h_dim1];
    target1->r = temp_r;
    target1->i = temp_i;
    target2->r = temp_r;
    target2->i = temp_i;
}
}
