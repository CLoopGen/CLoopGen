#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *coeff;
extern int size;
extern double x;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via artificial split
    // Each original operation is now spread over two iterations, doubling the loop count
    // Simulates a more memory-bound, less compute-intensive version
    int temp_i = 2 * (size - 1);
    for (i = temp_i - 1; i >= 0; --i) {
        if (i % 2 == 1) {
            sum *= x;
        } else {
            sum += coeff[i / 2];
        }
    }
}
