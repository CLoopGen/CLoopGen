#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    ossl_uintmax_t *n_ptr = &n;
    int max_iterations = ((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4;
    for (level = 1; level < max_iterations; level++) {
        if (((*n_ptr) >>= 4) == 0)
            break;
    }
}
