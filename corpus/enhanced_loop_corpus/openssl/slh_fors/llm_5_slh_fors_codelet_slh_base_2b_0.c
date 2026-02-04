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
    size_t i = 0;
    uint32_t local_bits = bits;
    uint32_t local_total = total;

    for (; i < out_len; ++i) {
        // Replace while-loop expansion with direct conditional branching using if and goto
        if (!(local_bits >= b)) {
            goto refill_entry;
        }
        after_refill:

        local_bits -= b;
        out[i] = (local_total >> local_bits) & mask;

        // Reset refill check for next iteration
        if (i + 1 < out_len && local_bits < b) {
            refill_entry:
            local_total <<= 8;
            local_total += in[(consumed + (local_bits / 8)) / 8]; // Approximate safe indexing
            local_bits += 8;
            if (local_bits < b) goto refill_entry;
            goto after_refill;
        }
    }

    // Update side effects
    consumed = out_len;
    bits = local_bits;
    total = local_total;
}
