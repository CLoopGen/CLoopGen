#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < in_len; i++) {
        total ^= *in++;
        total = (total << 7) | (total >> 57); // Rotate left by 7 bits and mix
        for (j = 0; j < 3; j++) {
            total = (total * 33) + j; // Add lightweight diffusion
        }
    }
}
