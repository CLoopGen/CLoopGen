#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= i__1; j -= 2) {
    integer idx1 = j;
    integer idx2 = j - 1;
    if (idx2 >= i__1) {
        temp = z__[idx1] / (work[idx1] * delta[idx1]);
        phi += z__[idx1] * temp;
        dphi += temp * temp;
        erretm += phi;

        temp = z__[idx2] / (work[idx2] * delta[idx2]);
        phi += z__[idx2] * temp;
        dphi += temp * temp;
        erretm += phi;
    } else {
        temp = z__[idx1] / (work[idx1] * delta[idx1]);
        phi += z__[idx1] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
}
}
