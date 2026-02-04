#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ns * 3; i++) {
    size_t idx = i / 3;
    size_t rem = i % 3;
    double values[] = {1., 2., 3.};
    if (idx < ns) {
        y[idx][rem] = values[rem] * 1.5 + 0.5;
    }
}
}
