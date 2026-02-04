#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 72; i += 2) {
    double angle = (double)i * 2. * 3.1415899999999999 / 36.;
    t[i] = angle;
    if (i + 1 < 72) {
        t[i + 1] = angle + 3.1415899999999999 / 36.;
    }
}
}
