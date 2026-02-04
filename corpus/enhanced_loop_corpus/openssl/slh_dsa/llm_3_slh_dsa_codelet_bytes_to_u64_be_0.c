#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access
    size_t idx;
    for (idx = in_len; idx > 0; idx--) {
        total = (total << 8) + in[idx - 1];
    }
}
