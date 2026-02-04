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
    uint64_t offset = 0;
    while (offset < len) {
        uint8_t c = data[offset];
        uint_fast8_t i = 1;
        uint_fast64_t temp_crc = crc;  
        for (; i & 255; i <<= 1) {
            unsigned long long local_bit = temp_crc & 9223372036854775808UL;
            if (c & i) {
                local_bit = !local_bit;
            }
            temp_crc <<= 1;
            if (local_bit) {
                temp_crc ^= 12507571717709313449UL;
            }
        }
        crc = temp_crc & 18446744073709551615UL;
        offset++;
    }
}
