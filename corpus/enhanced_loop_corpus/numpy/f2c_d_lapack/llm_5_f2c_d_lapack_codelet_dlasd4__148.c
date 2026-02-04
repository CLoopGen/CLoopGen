#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int skip_first = 0;
for (j = 1; j <= i__1; ++j) {
    if (j == 1) {
        skip_first = (z__[j] <= 0.0);
    }
    if (!skip_first || j > 1) {
        temp = z__[j] / (delta[j] * work[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
}
