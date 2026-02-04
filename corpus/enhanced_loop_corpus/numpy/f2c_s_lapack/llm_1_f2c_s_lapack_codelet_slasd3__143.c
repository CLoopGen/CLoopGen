#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *q;
extern integer q_dim1;
extern integer i__1;
extern integer i__;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every second element)
    // This modifies the access pattern to skip elements, creating a strided pattern
    // We now only update every second element to create non-unit stride
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        q[i__ + ktemp * q_dim1] = q[i__ + q_dim1];
    }
}
