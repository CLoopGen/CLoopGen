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
    for (a = 0; a < 512; a += 4) {
        temp = colram[charmap[a / 2 + 0]] << 0;
        temp |= colram[charmap[a / 2 + 256]] << 1;
        temp |= colram[charmap[a / 2 + 512]] << 2;
        if (a < 464)
            temp |= colram[charmap[a / 2 + 768]] << 3;
        buf[a + 0] = temp << 2;
        buf[a + 1] = temp << 2;
        buf[a + 2] = temp << 2;
        buf[a + 3] = temp << 2;
    }
}
