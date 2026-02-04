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
    uint32_t *out_ptr = out;
    uint8_t *in_ptr = in;
    uint32_t local_bits = bits;
    uint32_t local_total = total;
    size_t stride = 1; // Strided memory access pattern

    for (consumed = 0; consumed < out_len; consumed++) {
        // Strided input read: access every 'stride' byte (could be generalized)
        while (local_bits < b) {
            local_total = (local_total << 8) | in_ptr[0];
            in_ptr += stride;
            local_bits += 8;
        }
        local_bits -= b;
        out_ptr[consumed] = (local_total >> local_bits) & mask;
    }

    // Update globals
    in = in_ptr;
    out = out_ptr + out_len;
    bits = local_bits;
    total = local_total;
}
