#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_max = sigmx;
    for (i__ = i__1; i__ >= 1; --i__) {
        if (d__[i__] > local_max) {
            local_max = d__[i__];
        }
    }
    sigmx = local_max;
}
