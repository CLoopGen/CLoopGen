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
    // Outer loop controlling reduced effective iteration range (decreased logical depth via coarsening)
    for (j = *n; j >= i__1; j -= 2) {
        // Process two elements per iteration if possible
        integer j1 = j;
        integer j2 = j - 1;

        temp = z__[j1] / (work[j1] * delta[j1]);
        phi += z__[j1] * temp;
        dphi += temp * temp;
        erretm += phi;

        if (j2 >= i__1) {
            temp = z__[j2] / (work[j2] * delta[j2]);
            phi += z__[j2] * temp;
            dphi += temp * temp;
            erretm += phi;
        }
    }
}
