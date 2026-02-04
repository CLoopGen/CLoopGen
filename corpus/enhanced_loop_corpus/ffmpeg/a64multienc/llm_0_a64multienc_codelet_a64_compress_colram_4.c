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
    for (int outer = 0; outer < 2; outer++) {
        int offset = outer * 128;
        for (int a = 0; a < 128; a++) {
            int idx = a + offset;
            temp = colram[charmap[idx + 0]] << 0;
            temp |= colram[charmap[idx + 256]] << 1;
            temp |= colram[charmap[idx + 512]] << 2;
            if (idx < 232)
                temp |= colram[charmap[idx + 768]] << 3;
            buf[idx] = temp << 2;
        }
    }
}
