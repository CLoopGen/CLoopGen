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
    float num2 = num * 2.0f;
    for (i = 0; i < 20; i++) {
        v[2*i]     -= num * u[2*i];
        v[2*i + 1] -= num2 * u[2*i + 1];
    }
}
