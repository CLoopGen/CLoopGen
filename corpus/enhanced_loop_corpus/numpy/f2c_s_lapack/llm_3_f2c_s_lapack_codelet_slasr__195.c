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
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_next = c__[j + 1];
    real stemp_next = s[j + 1];
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer base_index = i__ * a_dim1;
        integer idx1_j = j + base_index;
        integer idx1_j1 = j + 1 + base_index;
        integer idx2_j = j + base_index;
        integer idx2_j1 = j + 1 + base_index;

        temp = a[idx1_j1];
        a[idx1_j1] = ctemp * temp - stemp * a[idx1_j];
        a[idx1_j] = stemp * temp + ctemp * a[idx1_j];

        temp = a[idx2_j1];
        a[idx2_j1] = ctemp_next * temp - stemp_next * a[idx2_j];
        a[idx2_j] = stemp_next * temp + ctemp_next * a[idx2_j];
    }
}
}
