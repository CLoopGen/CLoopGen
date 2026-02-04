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
    integer temp_r, temp_i;
    for (i__ = infqr + 1; i__ <= i__1; ++i__) {
        i__2 = kwtop + i__ - 1;
        i__3 = i__ + i__ * t_dim1;
        temp_r = t[i__3].r;
        temp_i = t[i__3].i;
        sh[i__2].r = temp_r;
        sh[i__2].i = temp_i;
    }
}
