#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[15];
    for (i = 0; i < 15; i++) {
        temp[i] = 1.;
        scale_abs[i] = temp[i];
    }
}
