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
    for (counter = 0; counter < len; counter++) {
        if ((crc & 0x8000) != 0) {
            crc = (crc << 1) ^ 0x1021;
        } else {
            crc = (crc << 1);
        }
        crc ^= *buf++;
        crc &= 0xFFFF;
    }
}
