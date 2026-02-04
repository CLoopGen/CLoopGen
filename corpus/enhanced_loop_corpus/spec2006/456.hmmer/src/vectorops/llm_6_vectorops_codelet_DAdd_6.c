#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double temp = 0.0;
    for (i = 0; i < n; i++) {
        temp = vec2[i];
        vec1[i] += temp;
    }
}
