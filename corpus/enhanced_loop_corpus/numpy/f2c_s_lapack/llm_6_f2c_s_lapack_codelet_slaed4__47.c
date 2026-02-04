#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_val;
    for (j = *n; j >= i__1; --j) {
        temp_val = z__[j] / delta[j];
        temp = temp_val;  // Introduce WAW dependency on 'temp' from original write
        phi += z__[j] * temp_val;
        dphi += temp_val * temp_val;
        erretm += phi;  // RAW: 'phi' read after write in same iteration
    }
}
