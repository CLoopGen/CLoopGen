#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t crc16tab[256];
extern  char *buf;
extern int len;
extern int counter;
extern uint16_t crc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_crc[2] = {crc, 0};
    int c = 0;
    for (counter = 0; counter < len; counter++) {
        local_crc[(counter + 1) % 2] = (local_crc[c] << 8) ^ crc16tab[((local_crc[c] >> 8) ^ buf[counter]) & 255];
        c = (counter + 1) % 2;
    }
    crc = local_crc[c];
}
