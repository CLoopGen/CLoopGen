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
real temp_local[1024]; // Assuming m <= 1024 for stack safety; could be dynamically allocated in practice
for (j = 1; j <= i__1; ++j) {
    for (i__ = *m; i__ >= 1; --i__) {
        temp_local[i__] = *alpha * b[i__ + j * b_dim1];
        i__2 = *m;
        for (k = i__ + 1; k <= i__2; ++k) {
            temp_local[i__] -= a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        if (nounit) {
            temp_local[i__] /= a[i__ + i__ * a_dim1];
        }
    }
    for (i__ = *m; i__ >= 1; --i__) {
        b[i__ + j * b_dim1] = temp_local[i__];
    }
}
}
