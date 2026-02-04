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
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (kk + 1 <= *m && 1 <= i__1) { // Reduced loop structure: collapsed nested loops into a single loop with manual indexing
        i__2 = *m;
        i__3 = i__1 * a_dim1;
        for (int idx = (kk + 1) + a_dim1; idx <= i__2 + i__3; ++idx) {
            a[idx].r = 0.; 
            a[idx].i = 0.;
        }
    }
}
