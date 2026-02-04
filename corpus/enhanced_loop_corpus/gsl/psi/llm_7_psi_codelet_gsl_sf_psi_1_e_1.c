#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    double factor = x * x;
    for (m = 0; m < M; ++m) {
        double xm = x + m;
        sum += 1. / (xm * xm);
        x = xm; // Introduce artificial WAW and RAW dependency on x (though x is extern, this creates intra-loop dependency)
    }
    x = factor; // Restore x to a function of original value (preserve some semantic consistency, though side effect remains)
}
