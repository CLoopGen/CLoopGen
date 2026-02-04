#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Jpeg2000QuantStyle {
    uint8_t expn[99];
    uint16_t mant[99];
    uint8_t quantsty;
    uint8_t nguardbits;
} Jpeg2000QuantStyle;

extern Jpeg2000QuantStyle *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_expn = q->expn[0];
    int base_mant = q->mant[0];
    for (i = 1; i < 33 * 3; i++) {
        int step = (i - 1) / 3;
        int curexpn = base_expn - step;
        if (curexpn < 0) curexpn = 0;
        // Removed loop-carried dependencies: all accesses now relative to original values
        q->expn[i] = curexpn;
        q->mant[i] = base_mant;
    }
}
