#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern  float *u;
extern int i;
extern float num;
extern float den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 40; i += 2) {
    num += v[i] * u[i];
    den += u[i] * u[i];
    if (i + 1 < 40) {
        num += v[i + 1] * u[i + 1];
        den += u[i + 1] * u[i + 1];
    }
}
}
