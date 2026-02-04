#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = ((*m) < j ? (*m) : j);
    if (i__2 >= 2) { // Increase effective work by unrolling inner loop by factor of 2
        for (i__ = 1; i__ <= i__2 - 1; i__ += 2) {
            a[i__     + j * a_dim1] *= mul;
            a[i__ + 1 + j * a_dim1] *= mul;
        }
        if (i__ <= i__2) { // Handle odd-sized remainder
            a[i__ + j * a_dim1] *= mul;
        }
    } else if (i__2 == 1) {
        a[1 + j * a_dim1] *= mul;
    }
}
}
