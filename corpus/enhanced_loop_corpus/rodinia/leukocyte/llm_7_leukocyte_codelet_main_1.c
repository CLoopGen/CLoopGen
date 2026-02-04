#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    for (i = 0; i < 36; i++) {
        double current_angle = (double)i * 2. * 3.1415899999999999 / 36.;
        t[i] = current_angle + prev;
        prev = current_angle;
    }
}
