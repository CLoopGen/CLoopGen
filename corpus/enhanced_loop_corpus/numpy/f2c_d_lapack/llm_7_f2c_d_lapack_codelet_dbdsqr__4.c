#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer *info;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer local_info = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (e[i__] != 0.) {
            local_info++;
        }
        e[i__] *= 2.0;  // Introduce WAW dependency: modifies e[i__] after read
    }
    *info += local_info;
}
