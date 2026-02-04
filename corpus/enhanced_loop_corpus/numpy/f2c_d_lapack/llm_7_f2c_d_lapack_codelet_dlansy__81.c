#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern integer j;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_max = 0.0;
    for (j = 1; j <= i__1; ++j) {
        doublereal col_max = 0.0;
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            d__1 = a[i__ + j * a_dim1];
            d__3 = (d__1 >= 0 ? d__1 : -d__1);
            col_max = (col_max >= d__3 ? col_max : d__3);
        }
        local_max = (local_max >= col_max ? local_max : col_max);
    }
    value = local_max;
}
