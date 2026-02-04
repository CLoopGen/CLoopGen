#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern float result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f, sum2 = 0.0f;
    int i;
    for (i = 0; i < n - 1; i += 2) {
        sum1 += vec1[i] * vec2[i];
        sum2 += vec1[i + 1] * vec2[i + 1];
    }
    if (i < n)
        sum1 += vec1[i] * vec2[i];
    result += sum1 + sum2;
}
