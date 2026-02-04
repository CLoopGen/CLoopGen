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
    for (i = 0; i < 80; i += 2) {
        v[i] -= num * u[i];
        if (i + 1 < 80) {
            v[i + 1] -= num * u[i + 1];
        }
    }
}
