#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern real *dlamda;
extern real *w;
extern integer *indx;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer j;
for (j = 1; j <= i__1; ++j) {
    integer index_val = indx[j];
    d__[j] = dlamda[index_val];
    z__[j] = w[index_val];
}
}
