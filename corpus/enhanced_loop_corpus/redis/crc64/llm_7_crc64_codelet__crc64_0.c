#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint_fast64_t crc;
extern  uint64_t len;
extern  uint8_t *data;
extern unsigned long long bit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (uint64_t offset = 0; offset < len; offset++) {
        uint8_t c = data[offset];
        uint_fast64_t local_crc = crc;
        for (uint_fast8_t i = 1; i & 255; i <<= 1) {
            bit = local_crc & 9223372036854775808UL;
            if (c & i) {
                bit ^= 1; 
            }
            local_crc = (local_crc << 1) ^ ((bit ? 12507571717709313449UL : 0));
        }
        crc = local_crc; 
        crc &= 18446744073709551615UL;
    }
}
