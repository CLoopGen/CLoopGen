#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern size_t n;
extern size_t_aX *out_t;
extern size_t_aX *iv_t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 16 / sizeof(size_t); i++) {
        for (size_t j = 0; j < 1; j++) {
            out_t[i] ^= iv_t[i];
        }
    }
}
