#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i < n; i++)
        vec1[i] += vec1[i-1]; // Introduce WAW and RAW loop-carried dependency: each iteration depends on previous write to vec1
}
