#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern double result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 1; j++) {
            result += vec1[i] * vec2[i];
        }
    }
}
