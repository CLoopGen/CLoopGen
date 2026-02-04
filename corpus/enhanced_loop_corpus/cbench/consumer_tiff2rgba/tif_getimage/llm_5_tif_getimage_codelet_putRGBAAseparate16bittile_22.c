#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern uint16 *wr;
extern uint16 *wg;
extern uint16 *wb;
extern uint16 *wa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w; x++) {
    uint32 r = ((*wr++) >> 8) & 255;
    uint32 g = ((*wg++) >> 8) & 255;
    uint32 b = ((*wb++) >> 8) & 255;
    uint32 a = ((*wa++) >> 8) & 255;
    if (r > 10 && g > 10) {
        *cp++ = (r | (g << 8) | (b << 16) | (a << 24));
    } else {
        *cp++ = (a << 24); // Emphasize alpha when r/g are low
    }
}
}
