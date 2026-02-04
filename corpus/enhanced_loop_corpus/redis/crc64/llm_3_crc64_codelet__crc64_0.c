#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint_fast64_t crc;
extern  uint64_t len;
extern  uint8_t *data;
extern unsigned long long bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated using arithmetic sequence)
    // Create an indirect access pattern: process all even-indexed bytes first, then odd
    uint64_t idx, offset;
    uint_fast8_t i;
    uint8_t c;

    // Process all even indices first (indirect-like access)
    for (idx = 0; 2 * idx < len; idx++) {
        offset = 2 * idx;
        c = data[offset];
        for (i = 1; i & 255; i <<= 1) {
            bit = crc & 9223372036854775808UL;
            if (c & i) {
                bit = !bit;
            }
            crc <<= 1;
            if (bit) {
                crc ^= 12507571717709313449UL;
            }
        }
        crc &= 18446744073709551615UL;
    }

    // Then process all odd indices
    for (idx = 0; 2 * idx + 1 < len; idx++) {
        offset = 2 * idx + 1;
        c = data[offset];
        for (i = 1; i & 255; i <<= 1) {
            bit = crc & 9223372036854775808UL;
            if (c & i) {
                bit = !bit;
            }
            crc <<= 1;
            if (bit) {
                crc ^= 12507571717709313449UL;
            }
        }
        crc &= 18446744073709551615UL;
    }
}
