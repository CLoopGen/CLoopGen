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

extern integer *n;
extern doublecomplex *t;
extern doublecomplex *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = i__1; i__ >= 1; --i__) {
    i__2 = i__ + *n;
    i__3 = i__ + i__ * t_dim1;
    work[i__2].r = t[i__3].r;
    work[i__2].i = t[i__3].i;
}
}
