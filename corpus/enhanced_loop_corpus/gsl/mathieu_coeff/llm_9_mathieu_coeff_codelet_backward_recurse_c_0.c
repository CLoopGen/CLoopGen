#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double aa;
extern double qq;
extern double *ff;
extern int ni;
extern int ii;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < ni && ii < 50; ii++) {
    nn = 99 - ii;
    int idx = ni - ii - 1;
    double base = (4 * nn * nn - aa);
    double scaled = base / qq;
    double adjusted = scaled + ff[idx];
    double reciprocal = -1.0 / adjusted;
    ff[idx] = reciprocal * 0.5; // Reduced impact to simulate damping
}
}
