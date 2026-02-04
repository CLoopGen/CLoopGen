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
for (j = *n; j >= i__1; --j) {
    integer idx = j;
    temp = z__[idx] / (work[idx] * delta[idx]);
    phi += z__[idx] * temp;
    dphi += temp * temp;
    erretm += phi;
}
}
