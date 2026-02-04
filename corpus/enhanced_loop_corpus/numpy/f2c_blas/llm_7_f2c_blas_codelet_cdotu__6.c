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

extern singlecomplex *cx;
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    singlecomplex temp_sum = ctemp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__;
        i__3 = i__;
        q__2.r = cx[i__2].r * cy[i__3].r - cx[i__2].i * cy[i__3].i;
        q__2.i = cx[i__2].r * cy[i__3].i + cx[i__2].i * cy[i__3].r;
        temp_sum.r = temp_sum.r + q__2.r;
        temp_sum.i = temp_sum.i + q__2.i;
    }
    ctemp = temp_sum;
}
