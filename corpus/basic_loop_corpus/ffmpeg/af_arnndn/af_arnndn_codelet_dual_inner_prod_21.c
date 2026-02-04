#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y01;
extern  float *y02;
extern int N;
extern float xy01;
extern float xy02;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < N; i++) {
    xy01 += (x[i] * y01[i]);
    xy02 += (x[i] * y02[i]);
}

}
