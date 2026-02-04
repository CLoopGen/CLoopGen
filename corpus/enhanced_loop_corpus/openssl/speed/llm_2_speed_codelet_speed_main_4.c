#include <stdio.h>

#include <inttypes.h>

extern size_t sigs_algs_len;
extern unsigned int i;
extern uint8_t sigs_doit[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then cover the rest in a second pass)
    size_t stride = 2;
    for (i = 0; i < sigs_algs_len; i += stride) {
        sigs_doit[i]--;
    }
    for (i = 1; i < sigs_algs_len; i += stride) {
        sigs_doit[i]--;
    }
}
