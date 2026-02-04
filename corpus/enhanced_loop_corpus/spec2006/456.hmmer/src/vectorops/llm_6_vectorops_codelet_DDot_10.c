#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (x = 0; x < n; x++) {
        temp += vec1[x] * vec2[x];
    }
    result += temp;
}
