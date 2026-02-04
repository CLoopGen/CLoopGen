#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coef;
int i;
int32_t tmp[64];

void init_vars() {
    // Allocate coef to be at least 8 * 8 = 64 int32_t elements to cover all (coef + i)[8 * j] accesses
    // Since i goes from 0 to 7, we need coef[i] for i in [0,7], and each stride by 8 -> max index: 7 + 8*7 = 63
    coef = (int32_t*)aligned_alloc(32, 64 * sizeof(int32_t));
    
    // Initialize tmp with dummy data to prevent undefined behavior
    for (int idx = 0; idx < 64; idx++) {
        tmp[idx] = (int32_t)(idx * 17 + 1);
    }
    
    // Initialize coef memory to zero to ensure defined output
    for (int idx = 0; idx < 64; idx++) {
        coef[idx] = 0;
    }
    
    // Reset loop index
    i = 0;
}