#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    for (i__ = *m; i__ >= 1; --i__) {
        doublereal temp = a[i__ + j * a_dim1];
        if (temp != 0.) {
            ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
        }
        if (j + 1 <= i__1) {
            temp = a[i__ + (j + 1) * a_dim1];
            if (temp != 0.) {
                ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
            }
        }
    }
}
}
