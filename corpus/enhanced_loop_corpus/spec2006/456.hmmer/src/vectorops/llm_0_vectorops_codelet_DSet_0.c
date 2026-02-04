#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 1; j++) {
            vec[i] = value;
        }
    }
}
