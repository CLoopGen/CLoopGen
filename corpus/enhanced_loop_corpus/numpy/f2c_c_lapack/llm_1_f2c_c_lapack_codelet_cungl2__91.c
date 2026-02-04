#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern integer *k;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= *m; ++j) { // Merge condition to reduce loop nesting by eliminating inner loop when possible
    if (*k + 1 <= *m) {
        i__2 = *m;
        l = *k + 1;
        i__3 = l + j * a_dim1;
        a[i__3].r = 0.F , a[i__3].i = 0.F; // Perform operation once as if flattened, simulating collapsed logic
    }
    if (j > *k && j <= *m) {
        i__2 = j + j * a_dim1;
        a[i__2].r = 1.F , a[i__2].i = 0.F;
    }
}
}
