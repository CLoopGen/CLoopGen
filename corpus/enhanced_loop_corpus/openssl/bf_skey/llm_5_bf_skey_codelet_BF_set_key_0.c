#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *data;
extern int i;
extern unsigned int *p;
extern unsigned int ri;
extern  unsigned char *d;
extern  unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (16 + 2); i++) {
        ri = 0;
        // Unroll the four byte reads with explicit index-based calculation
        unsigned int offset0 = (d - data);
        unsigned int offset1 = (offset0 + 1) % (end - data);
        unsigned int offset2 = (offset0 + 2) % (end - data);
        unsigned int offset3 = (offset0 + 3) % (end - data);

        ri |= ((unsigned int)data[offset0]) << 24;
        ri |= ((unsigned int)data[offset1]) << 16;
        ri |= ((unsigned int)data[offset2]) << 8;
        ri |= ((unsigned int)data[offset3]);

        d += 4; // Advance pointer by 4 bytes logically

        // Update d safely without branching using modulo-like arithmetic
        if (d >= end)
            d = data + (d - end);

        p[i] ^= ri;
    }
}
