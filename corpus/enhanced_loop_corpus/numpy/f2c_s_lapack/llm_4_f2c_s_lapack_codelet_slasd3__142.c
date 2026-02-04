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
    if (i__1 >= 1) {
        i__ = 1;
        u[i__ + u_dim1] = -u2[i__ + u2_dim1];
    }
}
