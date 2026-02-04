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
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a[i__ + (j + 1) * a_dim1];
            a[i__ + (j + 1) * a_dim1] = ctemp * temp - stemp * a[i__ + j * a_dim1];
            a[i__ + j * a_dim1] = stemp * temp + ctemp * a[i__ + j * a_dim1];
        }
    }
}

}
