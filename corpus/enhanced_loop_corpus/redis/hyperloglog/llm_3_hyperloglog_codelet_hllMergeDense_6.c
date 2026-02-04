#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array
    // Introduce an indirection table to simulate irregular access into reg_dense
    // This models scenarios like sparse data structures or gather operations.

    // Static index mapping to avoid dynamic allocation — simulates indirect access
    static uint16_t indices[1 << 14];
    static int indices_init = 0;
    if (!indices_init) {
        for (int j = 0; j < (1 << 14); j++) {
            // Pseudo-random but deterministic stride to generate non-consecutive access
            indices[j] = (j * 17 + 13) % ((1 << 14) - 10); // keep within bounds
        }
        indices_init = 1;
    }

    uint8_t *p = (uint8_t *)reg_dense;
    for (int i = 0; i < (1 << 14); i++) {
        int mapped_i = indices[i]; // Indirect iteration index

        unsigned long _byte = mapped_i * 6 / 8;
        unsigned long _fb = mapped_i * 6 & 7;
        unsigned long _fb8 = 8 - _fb;

        unsigned long b0 = p[_byte];
        unsigned long b1 = p[_byte + 1];
        uint8_t extracted_val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;

        reg_raw[mapped_i] = (reg_raw[mapped_i] > extracted_val) ? reg_raw[mapped_i] : extracted_val;
    }
}
