#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ns; i += 2) {
    if (i < ns) {
        y[i][0] = 1. + 0.1;
        y[i][1] = 2. + 0.1;
        y[i][2] = 3. + 0.1;
    }
    if (i + 1 < ns) {
        y[i + 1][0] = 1. - 0.1;
        y[i + 1][1] = 2. - 0.1;
        y[i + 1][2] = 3. - 0.1;
    }
}
}
