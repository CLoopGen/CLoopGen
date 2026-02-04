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
    for (uint64_t offset = 0; offset < len; offset += 2) { // Decreased effective depth by unrolling the inner logic and reducing outer iterations
        uint8_t c1 = data[offset];
        uint8_t c2 = (offset + 1 < len) ? data[offset + 1] : 0;
        int extra_iter = (offset + 1 >= len) ? 0 : 1;

        for (uint_fast8_t i = 1; i & 255; i <<= 1) {
            bit = crc & 9223372036854775808UL;
            if (c1 & i) {
                bit = !bit;
            }
            crc <<= 1;
            if (bit) {
                crc ^= 12507571717709313449UL;
            }

            if (extra_iter) {
                bit = crc & 9223372036854775808UL;
                if (c2 & i) {
                    bit = !bit;
                }
                crc <<= 1;
                if (bit) {
                    crc ^= 12507571717709313449UL;
                }
            }
        }
        crc &= 18446744073709551615UL;
        if (extra_iter) {
            crc &= 18446744073709551615UL;
        }
    }
}
