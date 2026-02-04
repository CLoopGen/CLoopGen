#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        vec[x] = vec[x] * scale + 1.0;
    }
}
