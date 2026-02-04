#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec[x] = value * 2.0;
            vec[x + 1] = value * 3.0;
        } else {
            vec[x] = value * 2.0;
        }
    }
}
