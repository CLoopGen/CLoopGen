#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    result = 0.0;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            result += vec1[x] * vec2[x] + vec1[x+1] * vec2[x+1];
        } else {
            result += vec1[x] * vec2[x];
        }
    }
}
