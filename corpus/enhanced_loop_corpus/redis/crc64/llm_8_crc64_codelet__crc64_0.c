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
    for (uint64_t offset = 0; offset < len; offset += 2) {
        uint8_t c1 = data[offset];
        uint8_t c2 = (offset + 1 < len) ? data[offset + 1] : 0;
        for (uint_fast8_t i = 1; i & 255; i <<= 1) {
            unsigned long long bit1 = crc & 9223372036854775808UL;
            if (c1 & i) {
                bit1 = !bit1;
            }
            unsigned long long bit2 = (crc << 1) & 9223372036854775808UL;
            if (c2 & i) {
                bit2 = !bit2;
            }
            crc <<= 2;
            if (bit1) {
                crc ^= 12507571717709313449UL;
            }
            if (bit2) {
                crc ^= 12507571717709313449UL >> 1;
            }
        }
        crc &= 18446744073709551615UL;
    }
}
