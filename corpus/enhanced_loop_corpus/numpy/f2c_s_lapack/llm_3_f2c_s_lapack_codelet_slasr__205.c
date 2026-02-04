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
        i__2 = *m;
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_i = i__;
            integer addr1 = base_i + j * stride;
            integer addr2 = base_i + (*n) * stride;
            temp = a[addr1];
            a[addr1] = stemp * a[addr2] + ctemp * temp;
            a[addr2] = ctemp * a[addr2] - stemp * temp;
        }
    }
}
}
