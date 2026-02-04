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
    // Variant 2: Strided memory access with a fixed stride of 2 (access every second element)
    uint32 stride = 2;
    uint32 *local_cp = cp;
    uint16 *local_wr = wr;
    uint16 *local_wg = wg;
    uint16 *local_wb = wb;
    uint32 count = 0;
    uint32 max_elements = (w + stride - 1) / stride; // Ceiling division to cover all needed

    for (x = 0; x < max_elements; x++) {
        uint32 idx = x * stride;
        uint32 r = ((uint32)((local_wr[idx] >> 8) & 255));
        uint32 g = ((uint32)((local_wg[idx] >> 8) & 255)) << 8;
        uint32 b = ((uint32)((local_wb[idx] >> 8) & 255)) << 16;
        uint32 a = (uint32)(255UL << 24);
        local_cp[count++] = r | g | b | a;
    }

    // Advance global pointers by total consumed input elements (strided)
    cp += count;
    wr += count * stride;
    wg += count * stride;
    wb += count * stride;
}
