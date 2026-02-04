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
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        if (i__ + 1 <= i__1) {
            doublereal abs_val_curr = (d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
            doublereal abs_val_next = (d__1 = dx[i__+1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (abs_val_curr > dmax__) {
                ret_val = i__;
                dmax__ = abs_val_curr;
            }
            if (abs_val_next > dmax__) {
                ret_val = i__ + 1;
                dmax__ = abs_val_next;
            }
        } else {
            if ((d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1))) > dmax__) {
                ret_val = i__;
                dmax__ = (d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
            }
        }
    }
}
