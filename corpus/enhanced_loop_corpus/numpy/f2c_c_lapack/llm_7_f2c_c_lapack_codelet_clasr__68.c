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
extern real *c__;
extern real *s;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
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
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            i__4 = i__ + a_dim1;
            real ar_temp_r = a[i__3].r;
            real ar_temp_i = a[i__3].i;
            real ai_temp_r = a[i__4].r;
            real ai_temp_i = a[i__4].i;
            a[i__3].r = ctemp * ar_temp_r - stemp * ai_temp_r;
            a[i__3].i = ctemp * ar_temp_i - stemp * ai_temp_i;
            a[i__4].r = stemp * ar_temp_r + ctemp * ai_temp_r;
            a[i__4].i = stemp * ar_temp_i + ctemp * ai_temp_i;
        }
    }
}
}
