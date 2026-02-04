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
    integer temp_r[64], temp_i[64];
    integer count = 0;
    for (i__ = infqr + 1; i__ <= i__1 && count < 64; ++i__) {
        i__2 = kwtop + i__ - 1;
        i__3 = i__ + i__ * t_dim1;
        temp_r[count] = t[i__3].r;
        temp_i[count] = t[i__3].i;
        ++count;
    }
    for (integer j = 0; j < count; ++j) {
        sh[kwtop + infqr + 1 + j - 1].r = temp_r[j];
        sh[kwtop + infqr + 1 + j - 1].i = temp_i[j];
    }
}
