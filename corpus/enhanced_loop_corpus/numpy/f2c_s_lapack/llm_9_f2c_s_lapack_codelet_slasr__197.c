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
for (j = 2; j <= i__1; j += 2) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    real ctemp_next = (j < i__1) ? c__[j] : 1.0F;
    real stemp_next = (j < i__1) ? s[j] : 0.0F;
    int apply_first = (ctemp != 1.F || stemp != 0.F);
    int apply_second = (j < i__1) && (ctemp_next != 1.F || stemp_next != 0.F);
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (apply_first) {
            temp = a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = ctemp * temp - stemp * a[i__ * a_dim1 + 1];
            a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a[i__ * a_dim1 + 1];
        }
        if (apply_second) {
            temp = a[j + 1 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = ctemp_next * temp - stemp_next * a[i__ * a_dim1 + 1];
            a[i__ * a_dim1 + 1] = stemp_next * temp + ctemp_next * a[i__ * a_dim1 + 1];
        }
    }
}
}
