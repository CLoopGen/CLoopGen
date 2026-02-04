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
extern doublecomplex *a;
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
if (*m >= 1 && i__1 >= 1) {
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (integer k = 1; k < j; ++k) {
            for (i__ = j; i__ <= i__2; ++i__) {
                integer index_b = i__ + j * b_dim1;
                integer index_a = i__ + j * a_dim1;
                b[index_b].r = a[index_a].r;
                b[index_b].i = a[index_a].i;
            }
        }
    }
}
}
