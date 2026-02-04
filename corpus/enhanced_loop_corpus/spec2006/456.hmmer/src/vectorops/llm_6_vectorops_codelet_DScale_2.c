#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec[x] *= scale;
            vec[x + 1] *= scale;
        } else {
            vec[x] *= scale;
        }
    }
}
