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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (j = i__1; j >= 1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
