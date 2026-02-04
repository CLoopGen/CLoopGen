#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *n;
extern real *c__;
extern real *s;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp2 = c__[j+1];
    real stemp2 = s[j+1];
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer idx1 = j + i__ * a_dim1;
        integer idx2 = j+1 + i__ * a_dim1;
        integer idxm = *m + i__ * a_dim1;

        temp = a[idx1];
        real temp2 = a[idx2];

        a[idx1] = stemp * a[idxm] + ctemp * temp;
        a[idxm] = ctemp * a[idxm] - stemp * temp;

        a[idx2] = stemp2 * a[idxm] + ctemp2 * temp2;
    }
}
}
