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
        integer increment = (e[i__] != 0.) ? 1 : 0;
        local_info += increment;
        e[i__] = e[i__] + 1.0; // Introduce WAW and RAW dependency on e[i__]
    }
    *info += local_info;
}
