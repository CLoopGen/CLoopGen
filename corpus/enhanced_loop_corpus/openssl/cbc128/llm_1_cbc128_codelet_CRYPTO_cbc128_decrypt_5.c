#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern size_t n;
extern size_t_aX *out_t;
extern size_t_aX *iv_t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 2; outer++) {
        for (size_t inner = 0; inner < 8 / sizeof(size_t); inner++) {
            size_t idx = outer * (8 / sizeof(size_t)) + inner;
            if (idx < 16 / sizeof(size_t)) {
                out_t[idx] ^= iv_t[idx];
            }
        }
    }
}
