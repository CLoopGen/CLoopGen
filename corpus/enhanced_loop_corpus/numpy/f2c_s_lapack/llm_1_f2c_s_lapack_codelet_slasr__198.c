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
if (*m >= 2 && *n >= 1) {
    for (j = *m; j >= 2; --j) {
        ctemp = c__[j - 1];
        stemp = s[j - 1];
        if (ctemp != 1.F || stemp != 0.F) {
            for (i__ = 1; i__ <= *n; ++i__) {
                for (integer inner = 0; inner < 1; ++inner) {
                    temp = a[j + i__ * a_dim1];
                    a[j + i__ * a_dim1] = ctemp * temp - stemp * a[i__ * a_dim1 + 1];
                    a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a[i__ * a_dim1 + 1];
                }
            }
        }
    }
}
}
