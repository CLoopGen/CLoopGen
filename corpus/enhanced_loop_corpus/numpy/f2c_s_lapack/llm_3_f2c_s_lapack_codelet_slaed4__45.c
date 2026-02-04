#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with temporary accumulation to change access pattern
    real temp_phi = 0.0f;
    for (j = i__1; j <= *n; ++j) {
        temp_phi += z__[j] * z__[j] / delta[j];
    }
    phi += temp_phi;
}
