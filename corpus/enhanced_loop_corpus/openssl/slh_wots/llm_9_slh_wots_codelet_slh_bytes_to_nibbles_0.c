#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (consumed = 0; consumed < in_len; consumed++) {
        uint8_t byte = *in++;
        // Increase arithmetic operations: simulate dummy computations to increase intensity
        uint8_t nibble1 = (byte >> 4) ^ 0x0A; // Add XOR operation
        uint8_t nibble2 = (byte & 15) + 5;    // Add addition
        nibble2 = (nibble2 << 1) | (nibble2 >> 7); // Rotate left by 1 (increased computation)
        *out++ = nibble1;
        *out++ = nibble2;
    }
}
