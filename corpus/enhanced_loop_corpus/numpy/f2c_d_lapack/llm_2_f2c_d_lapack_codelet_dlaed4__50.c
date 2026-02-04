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
    // Variant 1: Strided Memory Access (access every 2nd element in reverse)
    for (j = *n; j >= i__1; j -= 2) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
        
        // Handle odd index if needed by processing j-1 within bounds
        if (j - 1 >= i__1) {
            temp = z__[j-1] / delta[j-1];
            phi += z__[j-1] * temp;
            dphi += temp * temp;
            erretm += phi;
        }
    }
}
