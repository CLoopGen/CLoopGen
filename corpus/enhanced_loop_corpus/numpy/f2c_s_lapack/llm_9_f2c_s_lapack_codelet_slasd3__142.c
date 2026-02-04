#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *u;
extern real *u2;
extern integer u_dim1;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1 * 2; ++i__) {
        int idx = (i__ % i__1) + 1;
        u[idx + u_dim1] = -u2[idx + u2_dim1];
    }
}
