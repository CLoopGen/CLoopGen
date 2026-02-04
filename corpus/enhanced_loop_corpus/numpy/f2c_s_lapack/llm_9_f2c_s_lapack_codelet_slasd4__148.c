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
for (j = 2; j <= i__1; j += 2) {
    real temp1 = z__[j-1] / (delta[j-1] * work[j-1]);
    real temp2 = z__[j]   / (delta[j]   * work[j]);
    psi += z__[j-1] * temp1 + z__[j] * temp2;
    dpsi += temp1 * temp1 + temp2 * temp2;
    erretm += psi;
}
if (i__1 > 0 && i__1 % 2 == 1) {
    temp = z__[i__1] / (delta[i__1] * work[i__1]);
    psi += z__[i__1] * temp;
    dpsi += temp * temp;
    erretm += psi;
}
}
