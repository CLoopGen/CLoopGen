#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern float scalar;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++)
        for (int k = 0; k < 3; k++)
            result[i * 3 + k] = m1[i * 3 + k] * scalar;
}
