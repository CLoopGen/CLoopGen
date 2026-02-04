#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

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
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[j + 1 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = ctemp * temp - stemp * a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = stemp * temp + ctemp * a[j + i__ * a_dim1];
        }
    }
    if (j + 1 <= i__1) {
        ctemp = c__[j + 1];
        stemp = s[j + 1];
        if (ctemp != 1.F || stemp != 0.F) {
            i__2 = *n;
            for (i__ = 1; i__ <= i__2; ++i__) {
                temp = a[j + 2 + i__ * a_dim1];
                a[j + 2 + i__ * a_dim1] = ctemp * temp - stemp * a[j + 1 + i__ * a_dim1];
                a[j + 1 + i__ * a_dim1] = stemp * temp + ctemp * a[j + 1 + i__ * a_dim1];
            }
        }
    }
}
}
