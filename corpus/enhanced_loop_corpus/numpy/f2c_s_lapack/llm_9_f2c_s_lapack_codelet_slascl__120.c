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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real temp1 = a[i__ + j * a_dim1];
        real temp2 = (j + 1 <= i__1) ? a[i__ + (j + 1) * a_dim1] : temp1;
        temp1 *= mul;
        if (j + 1 <= i__1) temp2 *= mul;
        a[i__ + j * a_dim1] = temp1;
        if (j + 1 <= i__1) a[i__ + (j + 1) * a_dim1] = temp2;
    }
}
}
