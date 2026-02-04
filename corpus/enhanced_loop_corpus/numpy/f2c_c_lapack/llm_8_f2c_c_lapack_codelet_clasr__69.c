#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern integer *n;
extern real *c__;
extern real *s;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern singlecomplex q__3;
extern integer i__;
extern integer j;
extern singlecomplex temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 2; --j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = i__ + j * a_dim1;
            i__3 = i__ + a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            real temp_real = temp.r, temp_imag = temp.i;
            singlecomplex a_col1, a_colj;
            a_col1.r = a[i__3].r; a_col1.i = a[i__3].i;
            q__1.r = ctemp * temp_real - stemp * a_col1.r;
            q__1.i = ctemp * temp_imag - stemp * a_col1.i;
            a[i__2].r = q__1.r; a[i__2].i = q__1.i;
            q__1.r = stemp * temp_real + ctemp * a_col1.r;
            q__1.i = stemp * temp_imag + ctemp * a_col1.i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
        }
    }
}
}
