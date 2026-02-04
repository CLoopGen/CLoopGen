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
for (j = *n - 1; j >= 1; j -= 2) {  // Reduce trip count by stepping in increments of 2
    // Process two iterations at once if possible
    integer j1 = j;
    integer j2 = j - 1;

    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        // First rotation for j1
        ctemp = c__[j1];
        stemp = s[j1];
        if (ctemp != 1.F || stemp != 0.F) {
            temp = a[i__ + (j1 + 1) * a_dim1];
            a[i__ + (j1 + 1) * a_dim1] = ctemp * temp - stemp * a[i__ + j1 * a_dim1];
            a[i__ + j1 * a_dim1] = stemp * temp + ctemp * a[i__ + j1 * a_dim1];
        }

        // Second rotation for j2, if valid
        if (j2 >= 1) {
            ctemp = c__[j2];
            stemp = s[j2];
            if (ctemp != 1.F || stemp != 0.F) {
                temp = a[i__ + (j2 + 1) * a_dim1];
                a[i__ + (j2 + 1) * a_dim1] = ctemp * temp - stemp * a[i__ + j2 * a_dim1];
                a[i__ + j2 * a_dim1] = stemp * temp + ctemp * a[i__ + j2 * a_dim1];
            }
        }
    }
}
}
