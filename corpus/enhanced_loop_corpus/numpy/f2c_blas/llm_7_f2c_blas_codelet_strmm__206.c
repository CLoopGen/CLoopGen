#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp = 0.0f;
    for (i__ = *m; i__ >= 1; --i__) {
        real bi_temp = b[i__ + j * b_dim1];
        if (nounit) {
            bi_temp *= a[i__ + i__ * a_dim1];
        }
        i__2 = i__ - 1;
        real sum = 0.0f;
        for (k = 1; k <= i__2; ++k) {
            sum += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        bi_temp += sum;
        b[i__ + j * b_dim1] = *alpha * bi_temp;
        temp = bi_temp; 
    }
}
}
