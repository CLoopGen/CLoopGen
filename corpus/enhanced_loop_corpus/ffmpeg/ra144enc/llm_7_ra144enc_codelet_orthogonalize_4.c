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
    float acc = 0.0f;
    for (i = 0; i < 40; i++) {
        acc += num * u[i];
        v[i] -= acc;
        acc = v[i]; // Introduce artificial WAW and RAW dependency across iterations
    }
}
