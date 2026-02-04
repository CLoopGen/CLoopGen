#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (x = 0; x < n; x++) {
            vec[x] *= scale;
        }
    }
}
