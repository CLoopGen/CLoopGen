#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern float result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            result += vec1[x] * vec2[x] + vec1[x+1] * vec2[x+1];
        } else {
            result += vec1[x] * vec2[x];
        }
    }
}
