#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < inlen; outer += 8) {
        for (size_t i_offset = 0; i_offset < 8 && (outer + i_offset) < inlen; i_offset++) {
            size_t idx = outer + i_offset;
            in[idx] = (unsigned char)idx;
        }
    }
}
