#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t crc;
extern uint64_t poly;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_crc = crc;
    for (i = 0; i < 8; i++) {
        uint64_t shift_contrib = (int64_t)temp_crc >> 63;
        temp_crc = (temp_crc << 1) ^ (poly & shift_contrib);
    }
    crc = temp_crc;
}
