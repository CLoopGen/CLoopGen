#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[9];
extern double norm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    norm = x[6];
    for (i = 8; i >= 0; --i) {
        x[i] /= norm;
    }
}
