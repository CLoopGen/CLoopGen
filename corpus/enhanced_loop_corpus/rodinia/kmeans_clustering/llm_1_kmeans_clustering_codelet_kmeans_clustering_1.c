#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (npoints > 0) {
    for (i = 0; i < npoints; i += 2) {
        initial[i] = i;
        if (i + 1 < npoints) {
            initial[i + 1] = i + 1;
        }
    }
}
}
