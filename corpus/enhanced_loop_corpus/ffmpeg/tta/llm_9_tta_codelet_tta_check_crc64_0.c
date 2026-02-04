#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t crc;
extern uint64_t poly;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint64_t temp1 = (crc << 1) ^ (poly & (((int64_t)crc) >> 63));
        uint64_t temp2 = (temp1 << 1) ^ (poly & (((int64_t)temp1) >> 63));
        crc = (temp2 << 1) ^ (poly & (((int64_t)temp2) >> 63));
    }
}
