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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 offset = 0;
    for (x = 0; x < w; x += 4) {
        uint32 i0 = x + 0, i1 = x + 1, i2 = x + 2, i3 = x + 3;
        if (i0 < w) {
            cp[i0] = (((wr[i0] >> 8) & 255) | ((((uint32)(wg[i0] >> 8)) & 255) << 8) | ((((uint32)(wb[i0] >> 8)) & 255) << 16) | (255U << 24));
        }
        if (i1 < w) {
            cp[i1] = (((wr[i1] >> 8) & 255) | ((((uint32)(wg[i1] >> 8)) & 255) << 8) | ((((uint32)(wb[i1] >> 8)) & 255) << 16) | (255U << 24));
        }
        if (i2 < w) {
            cp[i2] = (((wr[i2] >> 8) & 255) | ((((uint32)(wg[i2] >> 8)) & 255) << 8) | ((((uint32)(wb[i2] >> 8)) & 255) << 16) | (255U << 24));
        }
        if (i3 < w) {
            cp[i3] = (((wr[i3] >> 8) & 255) | ((((uint32)(wg[i3] >> 8)) & 255) << 8) | ((((uint32)(wb[i3] >> 8)) & 255) << 16) | (255U << 24));
        }
    }
}
