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
    for (i = 0; i < 40; i += 4) {
        for (int k = 0; k < 4 && (i + k) < 40; k++) {
            int idx = i + k;
            num += v[idx] * u[idx];
            den += u[idx] * u[idx];
        }
    }
}
