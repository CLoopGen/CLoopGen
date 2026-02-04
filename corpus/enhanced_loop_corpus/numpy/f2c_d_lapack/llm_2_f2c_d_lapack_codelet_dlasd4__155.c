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
    // Variant 1: Strided memory access with stride of 2 (backward traversal with step)
    for (j = *n; j >= i__1; j -= 2) {
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
        
        // Handle adjacent element if within bounds
        if (j - 1 >= i__1) {
            integer j_prev = j - 1;
            temp = z__[j_prev] / (work[j_prev] * delta[j_prev]);
            phi += z__[j_prev] * temp;
            dphi += temp * temp;
            erretm += phi;
        }
    }
}
