#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (x = 0; x < n; x += 2)
        if (vec[x] > max)
            max = vec[x];
    // Handle odd-sized arrays by checking the last element if n is odd
    if (n % 2 == 1 && (n - 1) > 0 && vec[n - 1] > max)
        max = vec[n - 1];
}
