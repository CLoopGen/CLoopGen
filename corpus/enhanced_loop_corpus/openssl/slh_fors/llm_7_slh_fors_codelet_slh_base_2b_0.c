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
    size_t local_consumed = 0;
    uint32_t local_total = total;
    uint32_t local_bits = bits;
    const uint32_t required_bits = b;
    uint8_t *local_in = in;
    uint32_t *local_out = out;
    const uint32_t local_mask = mask;

    for (; local_consumed < out_len; local_consumed++) {
        for (; local_bits < required_bits; local_bits += 8) {
            local_total = (local_total << 8) | *local_in++;
        }
        local_bits -= required_bits;
        local_out[local_consumed] = (local_total >> local_bits) & local_mask;
    }

    total = local_total;
    bits = local_bits;
    in = local_in;
    out = local_out + local_consumed;
    consumed = local_consumed;
}
