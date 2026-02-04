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
    for (j = 2; j <= i__1; j += 2) {
        delta[j-1] = d__[j-1] - d__[*i__] - midpt;
        if (j <= i__1) {
            delta[j] = d__[j] - d__[*i__] - midpt;
        }
    }
}
