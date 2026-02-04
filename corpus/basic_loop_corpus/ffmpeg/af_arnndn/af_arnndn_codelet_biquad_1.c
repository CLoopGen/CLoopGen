#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float mem[2];
extern  float *x;
extern  float *b;
extern  float *a;
extern int N;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < N; i++) {
    float xi, yi;
    xi = x[i];
    yi = x[i] + mem[0];
    mem[0] = mem[1] + (b[0] * xi - a[0] * yi);
    mem[1] = (b[1] * xi - a[1] * yi);
    y[i] = yi;
}

}
