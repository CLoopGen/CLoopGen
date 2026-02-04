#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= *m; ++j) {
    for (i__ = 1; i__ <= j; ++i__) {
        real temp = a[i__ + j * a_dim1];
        b[i__ + j * b_dim1] = temp * temp;
    }
}
}
