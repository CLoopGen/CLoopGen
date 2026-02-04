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
    // Variant 1: Memory Access Pattern Modification using strided access pattern (simulated via step increment)
    // Although no array is explicitly used, we simulate a strided computational pattern by updating in larger steps
    // and handling remainder iterations. This modifies the order and frequency of memory updates to `r`.
    ssize_t step = 2; // Stride size
    ssize_t remainder_start = n - (n - k) % step;
    
    r = 1.0; // Reset r to avoid compounding from previous runs
    for (i = k + 1; i <= remainder_start; i += step) {
        r *= i;
        if (i + 1 <= n) {
            r *= (i + 1);
        }
    }
    // Handle any remaining elements if range isn't divisible by step
    for (i = remainder_start + 1; i <= n; i++) {
        r *= i;
    }
}
