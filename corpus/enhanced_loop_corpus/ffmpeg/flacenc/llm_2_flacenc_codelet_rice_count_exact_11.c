#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *res;
extern int n;
extern int k;
extern int i;
extern uint64_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    int stride = 2;
    int32_t *res_local = res;
    for (i = 0; i < n; i += stride) {
        int32_t v = -2 * res_local[i] - 1;
        v ^= v >> 31;
        count += (v >> k) + 1 + k;
    }
    // Handle any remaining element if n is odd
    if (n % 2 == 1) {
        int32_t v = -2 * res_local[n-1] - 1;
        v ^= v >> 31;
        count += (v >> k) + 1 + k;
    }
}
