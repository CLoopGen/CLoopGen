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
    int limit = n - (n % 4);
    for (x = 0; x < limit; x += 4) {
        sum1 += vec1[x] * vec2[x] + vec1[x+1] * vec2[x+1];
        sum2 += vec1[x+2] * vec2[x+2] + vec1[x+3] * vec2[x+3];
    }
    for (; x < n; x++) {
        result += vec1[x] * vec2[x];
    }
    result += sum1 + sum2;
}
