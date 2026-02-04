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
for (j = 1; j <= i__1; ++j) {
    integer temp_val = 0;
    for (i__ = *m; i__ >= 1; --i__) {
        if (a[(i__ - 1) + (j - 1) * a_dim1] != 0.) {
            temp_val = i__;
            break;
        }
    }
    ret_val = ((ret_val) >= (temp_val) ? (ret_val) : (temp_val));
}
}
