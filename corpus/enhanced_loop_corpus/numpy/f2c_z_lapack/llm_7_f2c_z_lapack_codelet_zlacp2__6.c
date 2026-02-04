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

extern integer *m;
extern doublereal *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer temp_r, temp_i;
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    temp_r = 0;
    temp_i = 0;
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        i__4 = i__ + j * a_dim1;
        temp_r = a[i__4];
        b[i__3].r = temp_r;
        b[i__3].i = temp_i;
    }
}
}
