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
    for (j = 1; j <= i__1; ++j) {
        if (d__[j] >= d__[*i__]) {
            work[j] = d__[j] + d__[*i__] + temp;
            delta[j] = d__[j] - d__[*i__] - temp;
        } else {
            work[j] = 0.0f;
            delta[j] = 0.0f;
        }
    }
}
