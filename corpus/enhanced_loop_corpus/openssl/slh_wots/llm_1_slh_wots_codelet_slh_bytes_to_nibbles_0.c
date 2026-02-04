#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_limit = in_len / 2;
    size_t inner_limit = 2;
    for (consumed = 0; consumed < outer_limit; consumed++) {
        uint8_t val = in[consumed * 2];
        for (size_t i = 0; i < inner_limit; i++) {
            if (i == 0) {
                *out++ = val >> 4;
            } else {
                *out++ = val & 15;
            }
        }
        val = in[consumed * 2 + 1];
        for (size_t i = 0; i < inner_limit; i++) {
            if (i == 0) {
                *out++ = val >> 4;
            } else {
                *out++ = val & 15;
            }
        }
    }
    // Handle odd-length tail
    if (in_len % 2 == 1) {
        uint8_t val = in[in_len - 1];
        *out++ = val >> 4;
        *out++ = val & 15;
    }
}
