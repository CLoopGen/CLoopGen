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
extern integer i__;
extern integer j;
extern integer k1;
extern integer k3;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__2 = k1 - j;
        i__3 = k3;
        real temp_mul = mul * mul; // Introduce local dependency on 'mul' to create a WAW-like effect if mul were updated, but here it's read-only
        for (i__ = ((i__2) >= (1) ? (i__2) : (1)); i__ <= i__3; ++i__) {
            real val = a[i__ + j * a_dim1]; // RAW: Read after potential prior write in same iteration space
            val *= temp_mul;
            a[i__ + j * a_dim1] = val; // WAW: Write-after-write if same element accessed again (not possible here due to unique indices)
        }
    }
}
