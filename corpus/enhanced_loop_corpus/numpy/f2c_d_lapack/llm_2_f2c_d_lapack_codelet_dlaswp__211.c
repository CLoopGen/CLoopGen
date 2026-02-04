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
    // Variant 1: Change memory access pattern to use consecutive indexing with pointer arithmetic
    // Instead of repeatedly calculating base + index * stride, we precompute row pointers and increment them
    doublereal *a_i = &a[i1];
    doublereal *a_ip;
    integer ip;
    integer k;
    integer ix_temp = ix;
    
    for (i__ = i1; i__3 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__3) {
        ip = ipiv[ix_temp];
        if (ip != i__) {
            a_ip = &a[ip];  // Base of row ip
            for (k = n32; k <= *n; ++k) {
                temp = a_i[k * a_dim1];
                a_i[k * a_dim1] = a_ip[k * a_dim1];
                a_ip[k * a_dim1] = temp;
            }
        }
        a_i += i__3;  // Move to next row in sequence
        ix_temp += *incx;
    }
}
