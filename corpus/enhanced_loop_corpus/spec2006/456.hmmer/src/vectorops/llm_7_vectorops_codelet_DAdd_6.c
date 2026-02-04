#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i < n; i++) {
        vec1[i] += vec2[i-1]; 
    }
    if (n > 0) {
        vec1[0] += vec2[0];
    }
}
