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
        uint64_t temp = crc;
        crc = (crc << 1);
        if (((int64_t)temp) < 0) {
            crc ^= poly;
        }
    }
}
