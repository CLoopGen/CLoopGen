#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];

void init_vars() {
    // No additional initialization needed beyond zero-initialization
    // Array size is fixed at 32000 as per the loop bounds
    // The loop uses i from 0 to 31999, which is within bounds
    // Each element will be assigned in the loop: a[i] = (i * 7) % 32000
    // Initialization of array not required since loop writes all elements
}