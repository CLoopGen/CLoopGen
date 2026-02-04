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
    // Reverse the loop order to eliminate loop-carried dependencies and change access pattern
    for (j = i__1; j >= kk + 1; --j) {
        i__2 = kk;
        for (i__ = i__2; i__ >= 1; --i__) {
            int idx = i__ + j * a_dim1;
            // Remove potential WAW and WAR hazards by ensuring unique write locations per iteration
            // Each (i__, j) pair accesses distinct memory location — same as original but reverse traversal
            a[idx].r = 0.0;
            a[idx].i = 0.0;
        }
    }
}
