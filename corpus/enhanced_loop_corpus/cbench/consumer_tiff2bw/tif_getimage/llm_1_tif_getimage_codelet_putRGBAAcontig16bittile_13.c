#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = w; x-- > 0;) {
        uint32 temp = 0;
        for (int j = 0; j < 4; j++) { // Unrolled operation via inner loop over channels
            temp |= ((uint32)((wp[j] >> 8) & 255) << (j * 8));
        }
        *cp++ = temp;
        wp += samplesperpixel;
    }
}
