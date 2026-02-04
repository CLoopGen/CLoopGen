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
value = 0.0;
i__2 = *m;
for (j = 1; j <= i__1; j += 2) {
    for (i__ = 1; i__ <= i__2; ++i__) {
        d__1 = a[i__ + j * a_dim1];
        d__2 = ((d__1) >= 0 ? (d__1) : -(d__1));
        d__3 = (j + 1 <= i__1) ? ((d__1 = a[i__ + (j+1) * a_dim1]), ((d__1) >= 0 ? d__1 : -d__1)) : 0.0;
        d__1 = (d__2 >= d__3) ? d__2 : d__3;
        value = (value >= d__1) ? value : d__1;
    }
}
}
