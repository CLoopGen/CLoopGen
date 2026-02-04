#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern int out_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_out = out;
    uint64_t local_digit = digit;
    int i;
    for (i = 0; i < out_len; i++) {
        local_out[i] = (uint8_t)(local_digit & 255);
        local_digit >>= 8;
    }
    out += out_len;
    digit = local_digit;
}
