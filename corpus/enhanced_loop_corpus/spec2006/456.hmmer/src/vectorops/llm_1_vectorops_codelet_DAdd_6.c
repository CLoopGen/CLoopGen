#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        vec1[0] += vec2[0];
        for (x = 1; x < n; x++)
            vec1[x] += vec2[x];
    }
}
