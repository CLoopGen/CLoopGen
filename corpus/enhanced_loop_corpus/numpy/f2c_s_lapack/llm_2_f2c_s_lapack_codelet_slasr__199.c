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
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer idx_j = j + i__ * a_dim1;
            integer idx_m = *m + i__ * a_dim1;
            temp = a[idx_j];
            a[idx_j] = stemp * a[idx_m] + ctemp * temp;
            a[idx_m] = ctemp * a[idx_m] - stemp * temp;
        }
    }
}
}
