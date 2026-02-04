#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (integer outer = 1; outer <= 1; ++outer) {
    for (j = 1; j <= i__1; ++j) {
        delta[j] = d__[j] - d__[*i__] - midpt;
    }
}
}
