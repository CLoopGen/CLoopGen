#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern integer ip1;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_d_j, temp_d_ip1;
    for (j = 1; j <= i__1; ++j) {
        temp_d_j = d__[j];
        temp_d_ip1 = d__[ip1];
        work[j] = temp_d_j + temp_d_ip1 + eta;
        delta[j] = temp_d_j - temp_d_ip1 - eta;
    }
}
