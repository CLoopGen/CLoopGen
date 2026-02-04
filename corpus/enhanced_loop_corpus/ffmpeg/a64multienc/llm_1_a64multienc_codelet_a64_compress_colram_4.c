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
    for (int stride = 0; stride < 64; stride++) {
        for (int step = 0; step < 4; step++) {
            a = stride * 4 + step;
            temp = colram[charmap[a + 0]] << 0;
            temp |= colram[charmap[a + 256]] << 1;
            temp |= colram[charmap[a + 512]] << 2;
            if (a < 232)
                temp |= colram[charmap[a + 768]] << 3;
            buf[a] = temp << 2;
        }
    }
}
