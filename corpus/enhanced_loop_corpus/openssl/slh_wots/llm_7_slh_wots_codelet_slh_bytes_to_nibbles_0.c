#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_in = in;
    uint8_t *local_out = out;
    size_t local_consumed = 0;

    for (; local_consumed < in_len; local_consumed++) {
        uint8_t val = *local_in++;
        *local_out++ = val >> 4;
        *local_out++ = val & 15;
    }

    in = local_in;
    out = local_out;
    consumed = local_consumed;
}
