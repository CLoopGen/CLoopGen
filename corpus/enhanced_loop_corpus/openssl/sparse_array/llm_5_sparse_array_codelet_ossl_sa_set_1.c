#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int max_iterations = ((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4;
    for (level = 1; level < max_iterations && (n >> 4) != 0; level++) {
        n >>= 4;
    }
    if (level < max_iterations)
        n >>= 4;
}
