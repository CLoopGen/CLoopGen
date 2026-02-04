#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[36];
for (i = 0; i < 36; i++) {
    indices[i] = 35 - i;
}
for (i = 0; i < 36; i++) {
    int idx = indices[i];
    t[idx] = (double)idx * 2. * 3.1415899999999999 / 36.;
}
}
