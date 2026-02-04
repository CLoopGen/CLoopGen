#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of accessing reg_dense based on bit-level indexing, we process consecutive bytes
    // and simulate the same logical extraction in a coalesced manner.
    uint8_t *p = (uint8_t *)reg_dense;
    for (int i = (1 << 14) - 24; i < (1 << 14); i++) {
        // Compute byte index and bit offset as before, but simplify control flow
        unsigned long _byte = (i * 6) >> 3;
        unsigned long _fb = (i * 6) & 7;
        unsigned long _fb8 = 8 - _fb;

        // Directly compute val without do-while
        unsigned long b0 = p[_byte];
        unsigned long b1 = p[_byte + 1];
        uint8_t computed_val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;  // 0x3F = (1 << 6) - 1

        // Update reg_raw with max(reg_raw[i], val)
        reg_raw[i] = (reg_raw[i] > computed_val) ? reg_raw[i] : computed_val;
    }
}
