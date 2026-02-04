#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *filter_coeffs;
extern  float *in;
extern int buffer_length;
extern int filter_length;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access
    // Instead of forward traversal, process the buffer from near the end down to filter_length
    // This changes data access locality and may affect cache behavior
    int start = buffer_length - 1;
    for (n = start; n >= filter_length; n--) {
        out[n] = in[n];
        for (i = 1; i <= filter_length; i++)
            out[n] -= filter_coeffs[i - 1] * out[n - i];
    }
    // Ensure n ends at a consistent exit state (first invalid index)
    n = buffer_length; 
}
