#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x, outer;
    const int unroll_factor = 2;
    int remainder = n % unroll_factor;
    
    for (x = 0; x < remainder; x++)
        vec[x] /= sum;
        
    for (x = remainder; x < n; x += unroll_factor) {
        vec[x] /= sum;
        if (x + 1 < n)
            vec[x + 1] /= sum;
    }
}
