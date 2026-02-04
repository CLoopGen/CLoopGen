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
    // Variant 1: Consecutive memory access with reversed array traversal (backward consecutive)
    uint32 *cp_end = cp + w;
    uint16 *wr_end = wr - w;
    uint16 *wg_end = wg - w;
    uint16 *wb_end = wb - w;
    uint16 *wa_end = wa - w;

    for (x = w; x-- > 0;) {
        --wr; --wg; --wb; --wa;
        a = *wa >> 4;
        r = (*wr * a) / 69375;
        g = (*wg * a) / 69375;
        b = (*wb * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }

    // Restore global pointers if needed (not required per problem scope)
}
