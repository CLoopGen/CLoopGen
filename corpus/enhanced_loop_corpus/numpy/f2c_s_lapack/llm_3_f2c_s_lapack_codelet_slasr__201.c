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
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_next = c__[j + 1];
    real stemp_next = s[j + 1];
    if (ctemp != 1.F || stemp != 0.F || ctemp_next != 1.F || stemp_next != 0.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_idx = i__;
            integer idx_j   = base_idx + j      * a_dim1;
            integer idx_jp1 = base_idx + (j + 1) * a_dim1;
            temp = a[idx_jp1];
            real temp2 = a[idx_jp1 + a_dim1];
            a[idx_jp1] = ctemp * temp - stemp * a[idx_j];
            a[idx_j] = stemp * temp + ctemp * a[idx_j];
            a[idx_jp1 + a_dim1] = ctemp_next * temp2 - stemp_next * a[idx_j + a_dim1];
            a[idx_j + a_dim1] = stemp_next * temp2 + ctemp_next * a[idx_j + a_dim1];
        }
    }
}
}
