#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern uint32_t b;
extern uint32_t *out;
extern size_t out_len;
extern size_t consumed;
extern uint32_t bits;
extern uint32_t total;
extern uint32_t mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < out_len * b && consumed < out_len; i++) {
        if ((i % b) == 0 && consumed < out_len) {
            bits -= b;
            *out++ = (total >> bits) & mask;
            consumed++;
        }
        if (bits < b + 8) {
            total = (total << 8) | *in++;
            bits += 8;
        }
    }
}
