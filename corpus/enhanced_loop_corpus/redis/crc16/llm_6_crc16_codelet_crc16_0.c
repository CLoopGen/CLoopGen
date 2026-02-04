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
    uint16_t temp_crc = crc;
    for (counter = 0; counter < len; counter++) {
        uint8_t index = ((temp_crc >> 8) ^ buf[counter]) & 255;
        temp_crc = (temp_crc << 8) ^ crc16tab[index];
    }
    crc = temp_crc;
}
