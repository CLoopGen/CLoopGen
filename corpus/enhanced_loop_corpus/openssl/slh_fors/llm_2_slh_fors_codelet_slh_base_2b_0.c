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



void loop() {
    size_t i;
    uint8_t *local_in = in;
    uint32_t *local_out = out;
    uint32_t local_bits = bits;
    uint32_t local_total = total;

    for (consumed = 0; consumed < out_len; consumed++) {
        if (local_bits < b) {
            local_total = (local_total << 8) | (*local_in);
            local_in++;
            local_bits += 8;
        }
        if (local_bits < b) {
            local_total = (local_total << 8) | (*local_in);
            local_in++;
            local_bits += 8;
        }
        // Unroll assumption: b <= 16, so at most two byte reads needed
        local_bits -= b;
        *local_out++ = (local_total >> local_bits) & mask;
    }

    // Update shared state
    in = local_in;
    out = local_out;
    bits = local_bits;
    total = local_total;
}
