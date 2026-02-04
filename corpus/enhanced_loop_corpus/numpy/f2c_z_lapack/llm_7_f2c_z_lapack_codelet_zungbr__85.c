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
    integer temp_r = 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
        i__2 = i__ + a_dim1;
        a[i__2].r = temp_r++;
        a[i__2].i = 0.;
    }
}
