#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < n; x++) {
    if (vec[x] != 0.0) {
        sum += vec[x];
    }
}
}
