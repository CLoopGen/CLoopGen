#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_local = temp;
    for (j = 1; j <= i__1; ++j) {
        work[j] = d__[j] + d__[*i__] + temp_local;
        delta[j] = work[j] - 2.0f * d__[*i__]; 
    }
}
