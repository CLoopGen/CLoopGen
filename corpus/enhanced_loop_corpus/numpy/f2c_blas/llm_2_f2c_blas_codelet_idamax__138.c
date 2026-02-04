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
    // Variant 1: Strided memory access (stride of 2)
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        if (i__ > i__1) break; // Ensure we don't exceed bounds due to stride
        if ((d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1))) <= dmax__) {
            goto L30;
        }
        ret_val = i__;
        dmax__ = (d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
      L30:
        ;
    }
}
