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
for (i__ = 1; i__ <= i__1; ++i__) {
    integer idx_work = i__ + *n;
    integer idx_t = i__ + i__ * t_dim1;
    work[idx_work].r = t[idx_t].r;
    work[idx_work].i = t[idx_t].i;
}
}
