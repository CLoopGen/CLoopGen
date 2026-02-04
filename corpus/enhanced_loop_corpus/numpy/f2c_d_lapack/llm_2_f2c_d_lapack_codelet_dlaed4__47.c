#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds adjustment
    integer stride = 2;
    integer j_start = (*n % stride == 0) ? *n : *n - (*n % stride);
    for (j = j_start; j >= i__1; j -= stride) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
        // Ensure j-1 is within bounds before accessing
        if (j - 1 >= i__1) {
            temp = z__[j - 1] / delta[j - 1];
            phi += z__[j - 1] * temp;
            dphi += temp * temp;
            erretm += phi;
        }
    }
}
