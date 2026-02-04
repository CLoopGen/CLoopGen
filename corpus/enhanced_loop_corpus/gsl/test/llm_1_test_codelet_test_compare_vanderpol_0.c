#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (ns > 0) {
    for (i = 0; i < ns; i += 2) {
        y[i][0] = 1.;
        y[i][1] = 0.;
        if (i + 1 < ns) {
            y[i + 1][0] = 1.;
            y[i + 1][1] = 0.;
        }
    }
}
}
