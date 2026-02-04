#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern  float *u;
extern int i;
extern float num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 4) {
        v[i]     -= num * u[i];
        if (i+1 < 40) v[i+1] -= num * u[i+1];
        if (i+2 < 40) v[i+2] -= num * u[i+2];
        if (i+3 < 40) v[i+3] -= num * u[i+3];
    }
}
