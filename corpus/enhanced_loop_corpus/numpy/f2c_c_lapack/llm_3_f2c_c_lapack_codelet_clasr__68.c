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
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_idx = i__;
            integer a_j_col = base_idx + j * stride;
            integer a_1_col = base_idx + stride;
            singlecomplex temp_val = a[a_j_col];
            singlecomplex* a_ptr_1 = &a[a_1_col];
            singlecomplex* a_ptr_j = &a[a_j_col];
            a_ptr_j->r = ctemp * temp_val.r - stemp * a_ptr_1->r;
            a_ptr_j->i = ctemp * temp_val.i - stemp * a_ptr_1->i;
            a_ptr_1->r = stemp * temp_val.r + ctemp * a_ptr_1->r;
            a_ptr_1->i = stemp * temp_val.i + ctemp * a_ptr_1->i;
        }
    }
}
}
