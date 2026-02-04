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
    float temp[40];
    for (i = 0; i < 40; i++) {
        temp[i] = num * u[i];
    }
    for (i = 0; i < 40; i++) {
        v[i] -= temp[i];
    }
}
