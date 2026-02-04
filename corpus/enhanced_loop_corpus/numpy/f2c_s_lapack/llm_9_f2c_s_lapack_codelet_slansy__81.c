#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *n;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern integer j;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *n;
    real temp_value1 = 0.0f;
    real temp_value2 = 0.0f;
    integer j2 = j + 1;
    for (i__ = j; i__ <= i__2; ++i__) {
        // Process two columns at once to increase arithmetic intensity
        r__1 = a[i__ + j * a_dim1];
        r__2 = (r__1 >= 0.0f) ? r__1 : -r__1;
        temp_value1 = (temp_value1 >= r__2) ? temp_value1 : r__2;

        if (j2 <= i__1 && i__ >= j2) {
            r__1 = a[i__ + j2 * a_dim1];
            r__3 = (r__1 >= 0.0f) ? r__1 : -r__1;
            temp_value2 = (temp_value2 >= r__3) ? temp_value2 : r__3;
        }
    }
    // Reduce to final value; simulate more complex reduction
    value = (temp_value1 >= temp_value2) ? temp_value1 : temp_value2;
}
}
