#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern float result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = result;
    for (x = 0; x < n; x++)
        temp += vec1[x] * vec2[x];
    result = temp;
}
