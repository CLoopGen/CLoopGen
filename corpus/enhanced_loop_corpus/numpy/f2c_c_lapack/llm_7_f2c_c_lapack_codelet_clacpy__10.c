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
extern singlecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    real *local_cache_r = (real*)malloc(i__2 * sizeof(real));
    real *local_cache_i = (real*)malloc(i__2 * sizeof(real));
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        local_cache_r[i__-1] = a[i__4].r;
        local_cache_i[i__-1] = a[i__4].i;
    }
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        b[i__3].r = local_cache_r[i__-1];
        b[i__3].i = local_cache_i[i__-1];
    }
    free(local_cache_r);
    free(local_cache_i);
}
}
