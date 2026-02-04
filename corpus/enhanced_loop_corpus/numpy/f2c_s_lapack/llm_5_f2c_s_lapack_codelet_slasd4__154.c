#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real psi;
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int skip_first = 0;
for (j = 1; j <= i__1; ++j) {
    if (j == 1 && skip_first) continue;
    temp = z__[j] / (work[j] * delta[j]);
    psi += z__[j] * temp;
    dpsi += temp * temp;
    if (dpsi < erretm) {
        erretm += psi;
    }
}
}
