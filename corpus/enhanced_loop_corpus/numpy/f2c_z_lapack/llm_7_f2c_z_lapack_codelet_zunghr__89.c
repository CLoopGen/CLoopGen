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
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse loop order to eliminate original loop-carried dependencies and change access pattern
    for (j = i__1; j >= 1; --j) {
        i__2 = *n;
        // Initialize off-diagonal elements as before, but in reverse column order
        for (i__ = i__2; i__ >= 1; --i__) {
            i__3 = i__ + j * a_dim1;
            a[i__3].r = 0.0;
            a[i__3].i = 0.0;
        }
        // Set diagonal element — now no dependency across iterations due to reversed independent updates
        i__2 = j + j * a_dim1;
        a[i__2].r = 1.0;
        a[i__2].i = 0.0;
        // Introduce artificial write-after-write avoidance via temporary
        doublereal temp_r = a[i__2].r;
        doublereal temp_i = a[i__2].i;
        a[i__2].r = temp_r;
        a[i__2].i = temp_i;
    }
}
