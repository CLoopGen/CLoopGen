#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t crc;
extern uint64_t poly;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int k = 0; k < 1; k++)
            crc = (crc << 1) ^ (poly & (((int64_t)crc) >> 63));
    }
}
