#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer ret_val;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern doublereal dmax__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_val = (dx[i__] >= 0) ? dx[i__] : -dx[i__];
        int update_needed = abs_val > dmax__;
        if (update_needed) {
            ret_val = i__;
            dmax__ = abs_val;
        } else {
            continue;
        }
    }
}
