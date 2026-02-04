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
    // Variant 2: Strided memory access (stride of 2) with bounds check
    uint32 stride = 2;
    uint32 limit = w / stride;

    for (x = 0; x < limit; x++) {
        uint32 index = x * stride;
        *cp++ = ((uint32)(((*((uint16*)((char*)wr + index * sizeof(uint16)))) >> 8) & 255) |
                   ((uint32)(((*((uint16*)((char*)wg + index * sizeof(uint16)))) >> 8) & 255) << 8) |
                   ((uint32)(((*((uint16*)((char*)wb + index * sizeof(uint16)))) >> 8) & 255) << 16) |
                   ((uint32)(255U << 24)));
    }

    // Adjust global pointers by the number of elements actually consumed
    wr += limit * stride;
    wg += limit * stride;
    wb += limit * stride;
}
