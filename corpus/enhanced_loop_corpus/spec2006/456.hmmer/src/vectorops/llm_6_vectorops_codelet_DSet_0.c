#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = value;
    for (x = 0; x < n; x++) {
        vec[x] = temp;
        temp = vec[x]; // Introduce RAW dependency: read-after-write on temp
    }
}
