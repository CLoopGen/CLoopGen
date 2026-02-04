#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sum = 0.0F;
    for (j = 1; j <= i__1; ++j) {
        temp1 = *alpha * x[j];
        temp2 = 0.F;
        i__2 = j - 1;
        temp_sum = 0.F; // Introduce local accumulation to modify dependency pattern
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp_sum += a[i__ + j * a_dim1] * x[i__]; // Accumulate temp2 early without write-write conflict
            y[i__] += temp1 * a[i__ + j * a_dim1];   // Keep read-after-write but decouple from temp2 update
        }
        temp2 = temp_sum; // Assign after loop to break WAW and RAW on temp2 inside inner loop
        y[j] = y[j] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
    }
}
