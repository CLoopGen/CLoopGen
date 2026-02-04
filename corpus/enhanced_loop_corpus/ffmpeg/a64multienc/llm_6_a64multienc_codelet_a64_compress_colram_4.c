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
    uint8_t temp1, temp2, temp3, temp4;
    for (a = 0; a < 256; a++) {
        temp1 = colram[charmap[a + 0]] << 0;
        temp2 = colram[charmap[a + 256]] << 1;
        temp3 = colram[charmap[a + 512]] << 2;
        temp4 = (a < 232) ? (colram[charmap[a + 768]] << 3) : 0;
        temp = temp1 | temp2 | temp3 | temp4;
        buf[a] = temp << 2;
    }
}
