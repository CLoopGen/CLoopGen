#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer i__;
integer j;
integer k;
doublereal t16[16];
doublereal tmp[4];
doublereal btmp[4];
doublereal temp;

void init_vars() {
    for (int idx = 0; idx < 16; ++idx) {
        t16[idx] = 1.0 + idx * 0.1;
    }
    
    for (int idx = 0; idx < 4; ++idx) {
        btmp[idx] = 100.0 + idx * 10.0;
    }
    
    for (int idx = 0; idx < 4; ++idx) {
        tmp[idx] = 0.0;
    }
    
    temp = 0.0;
    i__ = 0;
    j = 0;
    k = 0;
}