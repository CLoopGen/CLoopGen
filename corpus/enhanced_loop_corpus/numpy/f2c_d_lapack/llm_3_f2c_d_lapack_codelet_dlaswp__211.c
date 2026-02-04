#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
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
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use strided array access with indirect indexing via an index map
    // Instead of direct i__ and ip access, simulate indirection using a stride-adjusted index vector concept
    integer idx, ip_idx;
    integer k;
    integer stride = a_dim1;
    integer *indices = (integer*)malloc((i__1 - i1 + 1) * sizeof(integer));
    if (indices == NULL) return;

    // Precompute effective indices for the outer loop
    int count = 0;
    for (idx = i1; i__3 < 0 ? idx >= i__1 : idx <= i__1; idx += i__3) {
        indices[count++] = idx;
    }

    int idx_pos = 0;
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        idx = indices[idx_pos++];
        ip = ipiv[ix];
        if (ip != idx) {
            for (k = n32; k <= *n; ++k) {
                // Strided access through computed column offset
                i__2 = k * stride;
                temp = a[idx + i__2];
                a[idx + i__2] = a[ip + i__2];
                a[ip + i__2] = temp;
            }
        }
        ix += *incx;
    }

    free(indices);
}
