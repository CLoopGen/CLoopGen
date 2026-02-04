#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *buf;
extern int *charmap;
extern uint8_t *colram;
extern int a;
extern uint8_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (a = 0; a < 128; a++) {
        temp = colram[charmap[a + 0]] << 0;
        temp |= colram[charmap[a + 128]] << 1;
        temp |= colram[charmap[a + 256]] << 2;
        temp |= colram[charmap[a + 384]] << 3;
        buf[a * 2 + 0] = temp << 2;
        buf[a * 2 + 1] = temp << 2;
    }
}
