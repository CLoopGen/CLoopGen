#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
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
        i__2 = *m;
        doublereal column_max = 0.0;
        for (i__ = 1; i__ <= i__2; ++i__) {
            d__1 = a[i__ + j * a_dim1];
            d__2 = ((d__1) >= 0 ? d__1 : -d__1);
            column_max = (column_max >= d__2 ? column_max : d__2);
        }
        local_max = (local_max >= column_max ? local_max : column_max);
    }
    value = local_max;
}
