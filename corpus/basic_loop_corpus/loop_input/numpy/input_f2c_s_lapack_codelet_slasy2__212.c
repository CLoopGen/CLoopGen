#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer i__;
integer j;
integer k;
real t16[16];
real tmp[4];
real btmp[4];
real temp;

void init_vars() {
    for (int idx = 0; idx < 16; ++idx) {
        t16[idx] = 1.0f + (idx * 0.1f);
    }
    
    for (int idx = 0; idx < 4; ++idx) {
        btmp[idx] = (idx + 1) * 10.0f;
        tmp[idx] = 0.0f;
    }

    i__ = 0;
    j = 0;
    k = 0;
    temp = 0.0f;
}