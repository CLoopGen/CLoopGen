#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t crc;
extern uint64_t poly;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_crc[8];
    local_crc[0] = crc;
    for (i = 0; i < 8; i++) {
        if (i > 0) {
            local_crc[i] = (local_crc[i-1] << 1) ^ (poly & ((int64_t)local_crc[i-1] >> 63));
        }
    }
    crc = (crc << 1) ^ (poly & ((int64_t)local_crc[7] >> 63));
}
