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
real * restrict a_j = &a[j * a_dim1 + 1];
real * restrict a_n = &a[*n * a_dim1 + 1];
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a_j[i__];
            a_n[i__] = ctemp * a_n[i__] - stemp * temp;
            a_j[i__] = stemp * a_n[i__] + ctemp * temp;
        }
    }
}
}
