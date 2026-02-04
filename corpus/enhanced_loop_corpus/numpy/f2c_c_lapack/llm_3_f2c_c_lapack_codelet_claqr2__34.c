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

extern singlecomplex *sh;
extern singlecomplex *t;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer infqr;
extern integer kwtop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = 2;
for (i__ = infqr + 1; i__ <= i__1; i__ += stride) {
    i__2 = kwtop + i__ - 1;
    i__3 = i__ + i__ * t_dim1;
    if (i__ <= i__1) {
        sh[i__2].r = t[i__3].r;
        sh[i__2].i = t[i__3].i;
    }
    i__2 = kwtop + i__; 
    i__3 = (i__+1) + (i__+1) * t_dim1;
    if (i__ + 1 <= i__1) {
        sh[i__2].r = t[i__3].r;
        sh[i__2].i = t[i__3].i;
    }
}
}
