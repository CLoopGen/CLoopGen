#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double x;
extern int k;
extern double Ag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, with adjusted bounds)
    // We simulate a strided pattern by stepping backwards and using stride of 2, adjusting logic accordingly
    int k;
    double temp_sum = 0.0;
    for (k = 8; k >= 1; k -= 2) {
        temp_sum += lanczos_7_c[k] / (x + k);
        // Handle the next index in stride if exists
        if (k - 1 >= 1) {
            temp_sum += lanczos_7_c[k - 1] / (x + (k - 1));
        }
    }
    Ag += temp_sum;
}
