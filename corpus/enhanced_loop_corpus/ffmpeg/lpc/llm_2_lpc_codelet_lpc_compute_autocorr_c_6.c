#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled pattern
    // Instead of strided access by 2, we access consecutive elements in pairs
    // This improves spatial locality and enables better vectorization
    int k = j - 1;
    for (; k < len - 1; k += 2) {
        double term1 = data[k] * data[k - j];
        double term2 = data[k + 1] * data[k - j + 1];
        sum += term1 + term2;
    }
    // Handle potential last element if len is odd
    if (k == len - 1) {
        sum += data[k] * data[k - j];
    }
}
