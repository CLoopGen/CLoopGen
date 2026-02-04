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

extern doublecomplex *beta;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_index;
    doublereal temp_r = beta->r;
    doublereal temp_i = beta->i;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_index = i__ + i__ * a_dim1;
        a[temp_index].r = temp_r;
        a[temp_index].i = temp_i;
    }
}
