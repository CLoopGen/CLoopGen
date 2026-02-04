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
if (*n >= i__1) {
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
} else {
    j = i__1;
    temp = z__[j] / (work[j] * delta[j]);
    phi += z__[j] * temp;
    dphi += temp * temp;
    erretm += phi;
}
}
