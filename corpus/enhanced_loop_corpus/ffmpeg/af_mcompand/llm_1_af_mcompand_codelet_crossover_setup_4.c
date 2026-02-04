#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[9];
extern double norm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 9; ++i) {
    if (i == 0)
        norm = x[6];
    x[i] /= norm;
}
}
