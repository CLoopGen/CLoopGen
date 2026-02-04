#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 36; i++) {
        t[i] = (double)i * 2. * 3.1415899999999999 / 36.;
    }
}
}
