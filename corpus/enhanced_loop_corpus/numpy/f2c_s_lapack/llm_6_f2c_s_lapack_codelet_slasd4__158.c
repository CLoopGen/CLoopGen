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
    real temp_val = 0.0;
    for (j = *n; j >= i__1; --j) {
        temp_val = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp_val;
        dphi += temp_val * temp_val;
        erretm += phi;
    }
    temp = temp_val;
}
