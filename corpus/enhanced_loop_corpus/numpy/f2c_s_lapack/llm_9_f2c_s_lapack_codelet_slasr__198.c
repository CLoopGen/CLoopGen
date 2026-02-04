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
for (j = *m; j >= 2; j -= 2) {
    integer j1 = j;
    integer j2 = j - 1;
    if (j2 < 2) continue;
    real ctemp1 = c__[j1 - 1], stemp1 = s[j1 - 1];
    real ctemp2 = c__[j2 - 1], stemp2 = s[j2 - 1];
    int apply1 = (ctemp1 != 1.F || stemp1 != 0.F);
    int apply2 = (ctemp2 != 1.F || stemp2 != 0.F);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (apply1) {
            temp = a[j1 + i__ * a_dim1];
            a[j1 + i__ * a_dim1] = ctemp1 * temp - stemp1 * a[i__ * a_dim1 + 1];
            a[i__ * a_dim1 + 1] = stemp1 * temp + ctemp1 * a[i__ * a_dim1 + 1];
        }
        if (apply2) {
            temp = a[j2 + i__ * a_dim1];
            a[j2 + i__ * a_dim1] = ctemp2 * temp - stemp2 * a[i__ * a_dim1 + 1];
            a[i__ * a_dim1 + 1] = stemp2 * temp + ctemp2 * a[i__ * a_dim1 + 1];
        }
    }
}
}
