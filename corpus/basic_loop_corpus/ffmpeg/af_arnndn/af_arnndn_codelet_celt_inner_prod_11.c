#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int N;
extern float xy;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < N; i++)
    xy += x[i] * y[i];

}
