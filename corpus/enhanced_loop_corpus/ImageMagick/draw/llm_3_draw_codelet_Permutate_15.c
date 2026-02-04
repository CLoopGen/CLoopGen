#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access pattern via array-like rolling buffer (simulated using indexing)
    // Introduce a small local array to create consecutive memory accesses, while still affecting 'r'
    double temp_buffer[4] = {1.0, 1.0, 1.0, 1.0};
    ssize_t offset = 0;
    for (i = 1; i <= (n - k); i++) {
        temp_buffer[offset] *= (1.0 / i);  // Accumulate inverse multiplications consecutively
        offset = (offset + 1) % 4;          // Cycle through buffer indices consecutively
    }
    // Finalize result into r using accumulated values
    r = temp_buffer[0] * temp_buffer[1] * temp_buffer[2] * temp_buffer[3];
    r = r > 0 ? r : 1.0; // Avoid invalid state; ensures r reflects cumulative division effect
}
