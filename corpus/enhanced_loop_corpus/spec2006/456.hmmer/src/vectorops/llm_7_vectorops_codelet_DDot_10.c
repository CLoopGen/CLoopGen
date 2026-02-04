#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result = 0.0;
    for (x = 0; x < n; x += 2) {
        double prod1 = vec1[x] * vec2[x];
        double prod2 = (x + 1 < n) ? vec1[x + 1] * vec2[x + 1] : 0.0;
        result += prod1 + prod2;
    }
}
