#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real dmnmx;
extern integer start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = start + 1; i__ <= i__1; ++i__) {
    i__2 = start + 1;
    for (j = i__; j >= i__2; --j) {
        if (d__[j] > d__[j - 1]) {
            dmnmx = d__[j];
            d__[j] = d__[j - 1];
            d__[j - 1] = dmnmx;
        } else {
            break;
        }
    }
}
}
