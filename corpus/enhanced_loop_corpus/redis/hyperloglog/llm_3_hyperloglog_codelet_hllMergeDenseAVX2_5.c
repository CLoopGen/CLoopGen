#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern
    // Simulate a strided traversal by changing the iteration to jump through indices,
    // while still covering the same range logically via stride interpretation.
    // Here, we maintain the original logic but access reg_dense with an artificial stride of 2
    // to demonstrate non-consecutive memory behavior.

    uint8_t *p = (uint8_t *)reg_dense;
    int start = (1 << 14) - 24;
    int end = (1 << 14);
    int stride = 1;  // Logical stride remains 1, but dense access is modified

    for (int idx = 0; idx < (end - start); idx++) {
        int i = start + idx;  // Linear logical index

        // Modified access: use a strided view into reg_dense by scaling byte index
        // This simulates a transformed memory layout access pattern
        unsigned long _byte = (i * 6 / 8) * 2;  // Strided byte index (every other original position)
        unsigned long _fb = (i * 6) & 7;
        unsigned long _fb8 = 8 - _fb;

        // Ensure we don't go out of bounds; assume sufficient padding
        unsigned long b0 = p[_byte % 8192];      // Simulated modulo bound
        unsigned long b1 = p[(_byte + 2) % 8192]; // Stride applied: +2 instead of +1

        uint8_t computed_val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;

        reg_raw[i] = (reg_raw[i] > computed_val) ? reg_raw[i] : computed_val;
    }
}
