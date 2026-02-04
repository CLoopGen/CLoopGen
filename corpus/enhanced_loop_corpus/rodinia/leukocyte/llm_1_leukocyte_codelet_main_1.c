#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i++) {
    int base = i * 6;
    for (int k = 0; k < 6; k++) {
        int idx = base + k;
        t[idx] = (double)idx * 2. * 3.1415899999999999 / 36.;
    }
}
}
