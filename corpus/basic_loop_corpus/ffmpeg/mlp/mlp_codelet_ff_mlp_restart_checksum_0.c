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
    crc <<= 1;
    if (crc & 256)
        crc ^= 285;
    crc ^= (buf[num_bytes] >> (7 - i)) & 1;
}

}
