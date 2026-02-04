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
    for (i = 0; i < ((bit_size + 2) & 7); i++) {
        int bit = (buf[num_bytes] >> (7 - i)) & 1;
        crc = (crc << 1) ^ bit;
        crc = (crc & 256) ? (crc ^ 285) : crc;
    }
}
