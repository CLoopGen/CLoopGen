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
    // Variant 1: Strided memory access (stride of 2, traversing backwards with step 2)
    // This variant accesses only even or odd indices depending on size parity
    int stride = 2;
    int start = (size - 2) % stride == 0 ? size - 2 : size - 3;
    for (i = start; i >= 0; i -= stride) {
        sum *= x;
        sum += coeff[i];
    }
    // Handle remaining element if needed (compensate for skipped indices)
    if ((size - 2) % 2 != 0 && (size - 2) >= 0) {
        double temp_sum = sum;
        for (int j = size - 2; j > start && j >= 0; --j) {
            temp_sum *= x;
            temp_sum += coeff[j];
        }
        sum = temp_sum;
    }
}
