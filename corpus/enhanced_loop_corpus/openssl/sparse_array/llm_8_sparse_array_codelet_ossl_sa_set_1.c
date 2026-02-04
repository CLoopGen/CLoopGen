#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift_amount = 4;
    int max_iterations = ((int)sizeof(ossl_uintmax_t) * 8 + shift_amount - 1) / shift_amount;
    for (level = 1; level < max_iterations && n != 0; level++) {
        n >>= shift_amount;
        if ((n & 0xF) == 0) {
            n >>= 4;
        }
    }
}
