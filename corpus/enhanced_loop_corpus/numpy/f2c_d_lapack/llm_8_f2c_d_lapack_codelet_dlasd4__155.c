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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (j = *n; j >= i__1 + 2; j -= 3) {
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp * 1.5;
        dphi += temp * temp * 2.0;
        erretm += phi * 0.5;
        
        if (j-1 >= i__1) {
            temp = z__[j-1] / (work[j-1] * delta[j-1]);
            phi += z__[j-1] * temp * 1.5;
            dphi += temp * temp * 2.0;
            erretm += phi * 0.5;
        }
        
        if (j-2 >= i__1) {
            temp = z__[j-2] / (work[j-2] * delta[j-2]);
            phi += z__[j-2] * temp * 1.5;
            dphi += temp * temp * 2.0;
            erretm += phi * 0.5;
        }
    }
}
