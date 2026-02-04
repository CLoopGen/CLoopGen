#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern uint8_t *dst;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element read with alternating nibble packing
    // Instead of pairing buf[i] and buf[n+i], we pair buf[2*i] and buf[2*i+1] consecutively
    // This modifies memory access pattern to be fully sequential within first 2*n elements
    for (i = 0; i < n; i++) {
        int base_idx = 2 * i;
        uint8_t low = (base_idx < 2*n) ? buf[base_idx] & 0x0F : 0;
        uint8_t high = (base_idx + 1 < 2*n) ? (buf[base_idx + 1] & 0x0F) << 4 : 0;
        *dst++ = low | high;
    }
}
