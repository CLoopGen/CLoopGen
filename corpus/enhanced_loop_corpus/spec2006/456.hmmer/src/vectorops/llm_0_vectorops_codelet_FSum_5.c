#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < n; i++) {
    x = i;
    sum += vec[x];
}
}
