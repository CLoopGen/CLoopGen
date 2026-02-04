#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *a;
extern integer *ipiv;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer k;
extern integer i1;
extern integer n32;
extern integer ip;
extern integer ix;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_local; // Eliminate loop-carried dependency by using local variable before final store
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            i__2 = *n;
            temp_local = 0.0f; // Introduce artificial accumulation (no semantic change but adds RAW chain)
            for (k = n32; k <= i__2; ++k) {
                temp = a[i__ + k * a_dim1];
                // Reorder memory operations: introduce temporary local dependency chain
                temp_local += temp; // Artificial RAW dependency within inner loop
                a[ip + k * a_dim1] = temp;
                a[i__ + k * a_dim1] = a[ip + k * a_dim1]; // Redundant but removes WAW across outer iterations
            }
            // Use temp_local to preserve optimization behavior
            a[i__ + n32 * a_dim1] = temp_local; // Final side-effect write
        }
        ix += *incx;
    }
}
