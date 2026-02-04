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
for (counter = 0; counter < len; counter++)
    crc = (crc << 8) ^ crc16tab[((crc >> 8) ^ *buf++) & 255];

}
