#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double factor = 2. * 3.1415899999999999 / 36.;
for (i = 0; i < 18; i++) {
    t[i] = (double)i * factor;
    t[i + 18] = t[i] + 3.1415899999999999;
}
}
