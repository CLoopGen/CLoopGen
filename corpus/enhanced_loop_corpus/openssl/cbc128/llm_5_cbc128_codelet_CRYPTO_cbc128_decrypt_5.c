#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern size_t n;
extern size_t_aX *out_t;
extern size_t_aX *iv_t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16 / sizeof(size_t); n++) {
        if (iv_t[n] == 0)
            continue;
        out_t[n] ^= iv_t[n];
    }
}
