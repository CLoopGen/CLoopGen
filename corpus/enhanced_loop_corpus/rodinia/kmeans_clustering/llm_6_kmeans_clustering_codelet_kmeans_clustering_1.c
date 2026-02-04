#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < npoints; i++) {
        initial[i] = i;
        if (i > 0) {
            initial[i] += initial[i - 1]; // Introduce RAW dependency: each write depends on previous read
        }
    }
}
