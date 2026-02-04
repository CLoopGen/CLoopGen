#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[36];
    for (i = 0; i < 36; i++) {
        temp[i] = (double)i * 2. * 3.1415899999999999 / 36.;
    }
    for (i = 0; i < 36; i++) {
        t[i] = temp[i];
    }
}
