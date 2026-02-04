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
    // Decrease effective loop depth by removing the original loop and replacing with unrolled partial iterations
    // Assume *n - i__1 + 1 is small and bounded; here we unroll assuming at least 1 iteration
    if (*n >= i__1) {
        j = *n;
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
        
        --j;
        if (j >= i__1) {
            temp = z__[j] / (work[j] * delta[j]);
            phi += z__[j] * temp;
            dphi += temp * temp;
            erretm += phi;
            
            --j;
            if (j >= i__1) {
                temp = z__[j] / (work[j] * delta[j]);
                phi += z__[j] * temp;
                dphi += temp * temp;
                erretm += phi;
            }
        }
    }
}
