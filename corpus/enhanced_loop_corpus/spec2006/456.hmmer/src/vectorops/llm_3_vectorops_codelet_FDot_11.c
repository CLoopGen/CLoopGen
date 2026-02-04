#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern float result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (x = n - 1; x >= 0; x--)
        result += vec1[x] * vec2[x];
}
