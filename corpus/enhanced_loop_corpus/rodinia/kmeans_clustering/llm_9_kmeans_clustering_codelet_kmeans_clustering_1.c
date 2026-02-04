#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < npoints * 2; i++) {
        int idx = i % npoints;
        initial[idx] = (initial[idx] + i * i) % (npoints + 100);
    }
}
