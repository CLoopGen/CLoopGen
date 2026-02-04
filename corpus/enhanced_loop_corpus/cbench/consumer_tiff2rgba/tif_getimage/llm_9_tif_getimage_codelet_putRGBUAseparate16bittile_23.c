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
extern uint32 r;
extern uint32 g;
extern uint32 b;
extern uint32 a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = w * 2; x-- > 0;) {
        uint32 local_a = *wa++ >> 4;
        uint32 local_r = (*wr++ * local_a) / 69375;
        uint32 local_g = (*wg++ * local_a) / 69375;
        uint32 local_b = (*wb++ * local_a) / 69375;
        uint32 result = (local_r & 0xFF) | 
                        ((local_g & 0xFF) << 8) | 
                        ((local_b & 0xFF) << 16) | 
                        ((local_a & 0xFF) << 24);
        *cp++ = result;

        // Unroll simulation: process two elements per iteration if possible
        if (x-- > 0 && w > 0) {
            local_a = *wa++ >> 4;
            local_r = (*wr++ * local_a) / 69375;
            local_g = (*wg++ * local_a) / 69375;
            local_b = (*wb++ * local_a) / 69375;
            result = (local_r & 0xFF) | 
                     ((local_g & 0xFF) << 8) | 
                     ((local_b & 0xFF) << 16) | 
                     ((local_a & 0xFF) << 24);
            *cp++ = result;
        }
    }
}
