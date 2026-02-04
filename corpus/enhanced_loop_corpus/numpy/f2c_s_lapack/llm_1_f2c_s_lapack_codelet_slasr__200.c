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
for (j = *m - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *n;
        for (integer k = 0; k < i__1; ++k) {
            for (i__ = 1; i__ <= i__1; ++i__) {
                if (i__ == k + 1) {
                    temp = a[j + i__ * a_dim1];
                    a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
                    a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;
                }
            }
        }
    }
}
}
