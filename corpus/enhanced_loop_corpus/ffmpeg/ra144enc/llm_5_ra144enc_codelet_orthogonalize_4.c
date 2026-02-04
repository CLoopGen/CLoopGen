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
    for (i = 0; i < 40; i++) {
        if (v[i] > 0.0f) {
            v[i] -= num * u[i];
        } else {
            v[i] += num * u[i];
        }
    }
}
