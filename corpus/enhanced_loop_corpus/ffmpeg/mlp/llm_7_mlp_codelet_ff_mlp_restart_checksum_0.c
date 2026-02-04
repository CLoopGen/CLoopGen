#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern unsigned int bit_size;
extern int i;
extern int num_bytes;
extern int crc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift;
    uint8_t bit;
    for (i = 0; i < ((bit_size + 2) & 7); i++) {
        shift = 7 - i;
        bit = (buf[num_bytes] >> shift) & 1;
        crc = (crc << 1) ^ bit;
        if (crc & 256) {
            crc ^= 285;
        }
    }
}
