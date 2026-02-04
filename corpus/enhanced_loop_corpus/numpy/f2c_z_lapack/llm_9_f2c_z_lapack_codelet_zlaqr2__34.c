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

extern doublecomplex *sh;
extern doublecomplex *t;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer infqr;
extern integer kwtop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = infqr + 1; i__ <= i__1; i__ += 2) {
    i__2 = kwtop + i__ - 1;
    i__3 = i__ + i__ * t_dim1;
    sh[i__2].r = t[i__3].r;
    sh[i__2].i = t[i__3].i;
    if (i__ + 1 <= i__1) {
        i__2 = kwtop + i__;
        i__3 = (i__ + 1) + (i__ + 1) * t_dim1;
        sh[i__2].r = t[i__3].r;
        sh[i__2].i = t[i__3].i;
    }
}
}
