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
for (j = *m; j >= 2; --j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            integer idx_j = j + i__ * a_dim1;
            integer idx_1 = i__ * a_dim1 + 1;
            temp = a[idx_j];
            a[idx_j] = ctemp * temp - stemp * a[idx_1];
            a[idx_1] = stemp * temp + ctemp * a[idx_1];
        }
    }
}
}
