#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
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
for (j = 2; j <= i__1; j += 2) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            real temp1 = a[i__ + (j + 1) * a_dim1];
            real temp2 = a[i__ + j * a_dim1];
            a[i__ + (j + 1) * a_dim1] = ctemp * temp1 - stemp * temp2;
            a[i__ + j * a_dim1] = stemp * temp1 + ctemp * temp2;

            temp1 = a[i__ + (j + 2) * a_dim1];
            temp2 = a[i__ + (j + 1) * a_dim1];
            a[i__ + (j + 2) * a_dim1] = ctemp * temp1 - stemp * temp2;
            a[i__ + (j + 1) * a_dim1] = stemp * temp1 + ctemp * temp2;
        }
    }
}
}
