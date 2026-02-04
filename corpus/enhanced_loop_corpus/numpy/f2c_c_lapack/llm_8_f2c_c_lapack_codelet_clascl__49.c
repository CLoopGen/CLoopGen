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

extern integer *m;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_r, temp_i;
for (j = 1; j <= i__1; ++j) {
    i__2 = ((j) <= (*m) ? (j) : (*m));
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        temp_r = a[i__4].r;
        temp_i = a[i__4].i;
        a[i__4].r = mul * temp_r;
        a[i__4].i = mul * temp_i;
    }
}
}
