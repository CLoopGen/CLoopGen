#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, processing every second element in descending order
    // This changes access pattern to reduce cache contention or simulate sparse data access
    phi = dphi = erretm = 0.0;
    integer stride = 2;
    // Adjust starting index to ensure it's within bounds and respects stride
    integer start = (*n % 2 == i__1 % 2) ? *n : *n - 1;
    for (j = start; j >= i__1; j -= stride) {
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
    // Handle remaining element if range includes an odd count and i__1 is not reached
    if ((*n - i__1 + 1) % 2 == 0 && *n >= i__1 + 1) {
        j = *n - ((*n - i__1 + 1) % 2 == 0 ? 1 : 0);
        if (j >= i__1 && j < *n) {
            temp = z__[j] / (work[j] * delta[j]);
            phi += z__[j] * temp;
            dphi += temp * temp;
            erretm += phi;
        }
    }
}
