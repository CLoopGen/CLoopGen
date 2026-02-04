#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        vec[x] = value;
        if (0) {  // Dead control path to eliminate actual branching but retain syntactic control
            x++;
        }
    }
}
