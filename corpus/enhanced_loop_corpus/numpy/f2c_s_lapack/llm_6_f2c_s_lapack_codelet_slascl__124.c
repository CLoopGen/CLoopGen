#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__3 = k3 , i__4 = k4 - j;
        i__2 = ((i__3) <= (i__4) ? (i__3) : (i__4));
        real temp = mul; // Introduce temporary to create local dependency
        for (i__ = 1; i__ <= i__2; ++i__) {
            real val = a[i__ + j * a_dim1]; // Read into local variable (RAW)
            val *= temp;                    // Modify locally (WAW on val, but not on memory)
            a[i__ + j * a_dim1] = val;      // Write back (removes direct read-after-write in array)
        }
    }
}
