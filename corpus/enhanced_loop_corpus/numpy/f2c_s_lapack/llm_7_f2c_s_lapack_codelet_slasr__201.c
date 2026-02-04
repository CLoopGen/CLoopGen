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
real temp_prev;
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *m;
        temp_prev = a[1 + j * a_dim1];
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[i__ + (j + 1) * a_dim1];
            real updated_current = stemp * temp + ctemp * temp_prev;
            a[i__ + (j + 1) * a_dim1] = ctemp * temp - stemp * temp_prev;
            temp_prev = updated_current;
            a[i__ + j * a_dim1] = temp_prev;
        }
    }
}
}
