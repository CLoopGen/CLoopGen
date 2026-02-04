#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 36; i++) {
        if (i >= 12 && i < 24) {
            continue;
        }
        t[i] = (double)i * 2. * 3.1415899999999999 / 36.;
    }
}
