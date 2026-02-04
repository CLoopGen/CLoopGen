#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        if (j % 2 == 0) {
            t[j + 2 + j * t_dim1] = 0.F;
        } else {
            t[j + 3 + j * t_dim1] = 0.F;
        }
    }
}
