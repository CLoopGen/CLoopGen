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
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n - 1; j >= 1; j -= 2) {
    integer j1 = j;
    integer j2 = j - 1;
    if (j2 < 1) continue;
    ctemp = c__[j1];
    stemp = s[j1];
    real ctemp2 = c__[j2];
    real stemp2 = s[j2];
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (ctemp != 1.F || stemp != 0.F) {
            temp = a[i__ + j1 * a_dim1];
            a[i__ + j1 * a_dim1] = stemp * a[i__ + *n * a_dim1] + ctemp * temp;
            a[i__ + *n * a_dim1] = ctemp * a[i__ + *n * a_dim1] - stemp * temp;
        }
        if (ctemp2 != 1.F || stemp2 != 0.F) {
            temp = a[i__ + j2 * a_dim1];
            a[i__ + j2 * a_dim1] = stemp2 * a[i__ + *n * a_dim1] + ctemp2 * temp;
            a[i__ + *n * a_dim1] = ctemp2 * a[i__ + *n * a_dim1] - stemp2 * temp;
        }
    }
}
}
