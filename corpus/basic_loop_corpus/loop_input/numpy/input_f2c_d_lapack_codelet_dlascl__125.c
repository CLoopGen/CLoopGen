#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k1;
integer k3;
doublereal mul;

void init_vars() {
    // Set array dimensions and loop bounds
    a_dim1 = 1024;  // leading dimension
    k1 = 2048;
    k3 = 1024;
    i__1 = 512;     // j goes from 1 to i__1
    mul = 1.5;      // scaling factor
    
    // Allocate approximately 8MB of data (1024 * 1024 * sizeof(double))
    a = (doublereal*)calloc(a_dim1 * k3, sizeof(doublereal));
    
    // Ensure initialization covers all potential accesses:
    // j in [1, i__1], i__ in [max(k1-j,1), k3]
    // So max j is 512, min k1-j is k1-512 = 1536, but bounded by k3=1024
    // Therefore inner loop runs only when max(k1-j,1) <= k3
    // To avoid out-of-bounds, we allocated up to a_dim1*k3
}