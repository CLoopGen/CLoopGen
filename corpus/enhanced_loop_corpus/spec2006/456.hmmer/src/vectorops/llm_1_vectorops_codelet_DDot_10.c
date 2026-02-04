#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = n / 2;
    int remainder = n % 2;
    int x;

    for (x = 0; x < outer; x++) {
        result += vec1[2*x] * vec2[2*x];
        result += vec1[2*x+1] * vec2[2*x+1];
    }

    if (remainder) {
        result += vec1[n-1] * vec2[n-1];
    }
}
