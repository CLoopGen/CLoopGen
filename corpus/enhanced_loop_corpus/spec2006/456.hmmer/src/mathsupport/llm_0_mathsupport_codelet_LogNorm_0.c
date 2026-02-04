#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int x1;
for (x1 = 0; x1 < n; x1++) {
    x = x1;
    if (vec[x] > max)
        max = vec[x];
}
}
