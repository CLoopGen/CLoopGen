#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = n - 1; x >= 0; x--)
        vec1[x] = vec2[x];
}
