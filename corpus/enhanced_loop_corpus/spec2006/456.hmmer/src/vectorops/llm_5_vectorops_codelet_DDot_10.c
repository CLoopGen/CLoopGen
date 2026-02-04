#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        if (x % 2 == 0) {
            result += vec1[x] * vec2[x];
        } else {
            result += 0.0;
        }
    }
}
