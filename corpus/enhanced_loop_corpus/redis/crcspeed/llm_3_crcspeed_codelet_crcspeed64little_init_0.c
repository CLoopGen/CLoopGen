#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t table[8][256];
extern uint64_t crc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int n = 0; n < 256; n++) {
    uint64_t *table_row = table[0];
    crc = table_row[n];
    for (int k = 1; k < 8; k++) {
        uint64_t *target_table = table[k];
        crc = table_row[crc & 255] ^ (crc >> 8);
        target_table[n] = crc;
    }
}
}
