#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (integer k = j + 1; k <= i__2; ++k) {
        for (i__ = k; i__ <= k; ++i__) { // Artificially increased nesting depth with constrained inner loop
            a[i__ + j * a_dim1] = *alpha;
        }
    }
}
}
