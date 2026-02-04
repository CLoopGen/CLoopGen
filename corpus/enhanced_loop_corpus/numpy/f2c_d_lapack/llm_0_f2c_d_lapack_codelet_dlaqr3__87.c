#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        for (integer k = 2; k <= 3; ++k) {
            t[j + k + j * t_dim1] = 0.;
        }
    }
}
