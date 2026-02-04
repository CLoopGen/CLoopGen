#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t bit_indices[64];
    size_t total_bits = sizeof(value) * 8;
    for (i = 0; i < total_bits; i++) {
        bit_indices[i] = i;
    }
    for (i = 0; i < total_bits; i++) {
        size_t idx = bit_indices[i];
        ret += (((value >> idx) & 1) != 0);
    }
}
