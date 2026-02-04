#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer;
    size_t inner;
    size_t block_size = 16;
    for (outer = 0; outer < len; outer += block_size) {
        for (inner = 0; inner < block_size; ++inner) {
            size_t i = outer + inner;
            if (i >= len) break;
            out[i] = in1[i] ^ in2[i];
        }
    }
}
