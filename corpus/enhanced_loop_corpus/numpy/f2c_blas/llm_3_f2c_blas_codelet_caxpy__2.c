#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *ca;
extern singlecomplex *cx;
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive reverse traversal: access arrays from high to low index
integer j__;
for (j__ = i__1; j__ >= 1; --j__) {
    // Reverse sequential access
    q__2.r = ca->r * cx[j__].r - ca->i * cx[j__].i;
    q__2.i = ca->r * cx[j__].i + ca->i * cx[j__].r;
    q__1.r = cy[j__].r + q__2.r;
    q__1.i = cy[j__].i + q__2.i;
    cy[j__].r = q__1.r;
    cy[j__].i = q__1.i;
}
}
