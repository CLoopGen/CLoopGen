#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern  float *m2;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int idx = i * 3 + j;
            result[idx] = m1[idx] - m2[idx];
        }
    }
}
