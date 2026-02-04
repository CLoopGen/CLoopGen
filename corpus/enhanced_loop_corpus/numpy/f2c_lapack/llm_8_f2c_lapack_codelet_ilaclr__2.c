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
extern singlecomplex *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer temp_sum = 0;
    for (i__ = *m; i__ >= 1; --i__) {
        i__2 = i__ + j * a_dim1;
        temp_sum += (a[i__2].r * a[i__2].r) + (a[i__2].i * a[i__2].i);
        if (temp_sum > 1e-5F) {
            break;
        }
    }
    ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
}
}
