#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and indirect indexing via offsets
    // We change the access pattern by precomputing strided offsets and accessing array elements
    // using explicit stride-based index calculations to simulate a more cache-unfriendly,
    // but functionally equivalent, pattern. Also reverse the outer loop for variation.

    integer j;
    integer stride_b = b_dim1;
    integer stride_a = a_dim1;
    integer m_val = *m;
    doublereal alpha_val = *alpha;
    logical nounit_flag = nounit;

    // Reverse iteration over j to alter access sequence
    for (j = i__1; j >= 1; --j) {
        if (alpha_val != 1.0) {
            for (i__ = 1; i__ <= m_val; ++i__) {
                // Use explicit stride-based indexing
                b[i__ * 1 + j * stride_b] *= alpha_val;  // Unit stride in i, strided in j
            }
        }

        // Access k from m down to 1 remains, but now with offset variables
        for (k = m_val; k >= 1; --k) {
            integer idx_b_kj = k + j * stride_b;
            if (b[idx_b_kj] != 0.0) {
                if (nounit_flag) {
                    b[idx_b_kj] /= a[k + k * stride_a];
                }
                // Apply update using strided access to column k of A
                for (i__ = 1; i__ <= k - 1; ++i__) {
                    integer idx_a_ik = i__ + k * stride_a;  // Strided access: column k, row i
                    b[i__ + j * stride_b] -= b[idx_b_kj] * a[idx_a_ik];
                }
            }
        }
    }
}
