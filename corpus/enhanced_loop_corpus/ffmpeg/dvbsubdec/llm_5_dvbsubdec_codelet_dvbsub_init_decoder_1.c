#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DVBSubCLUT {
    int id;
    int version;
    uint32_t clut4[4];
    uint32_t clut16[16];
    uint32_t clut256[256];
    struct DVBSubCLUT *next;
} DVBSubCLUT;

extern DVBSubCLUT default_clut;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 256; i++) {
    if (i >= 8 && (i & 136) == 136) {
        r = ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
        g = ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
        b = ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
        a = 255;
    } else if (i < 8) {
        r = (i & 1) ? 255 : 0;
        g = (i & 2) ? 255 : 0;
        b = (i & 4) ? 255 : 0;
        a = 63;
    } else {
        int bit1 = i & 1, bit2 = i & 2, bit4 = i & 4;
        int bit16 = i & 16, bit32 = i & 32, bit64 = i & 64;
        if ((i & 136) == 128) {
            r = 127 + (bit1 ? 43 : 0) + (bit16 ? 85 : 0);
            g = 127 + (bit2 ? 43 : 0) + (bit32 ? 85 : 0);
            b = 127 + (bit4 ? 43 : 0) + (bit64 ? 85 : 0);
            a = 255;
        } else {
            r = (bit1 ? 85 : 0) + (bit16 ? 170 : 0);
            g = (bit2 ? 85 : 0) + (bit32 ? 170 : 0);
            b = (bit4 ? 85 : 0) + (bit64 ? 170 : 0);
            a = ((i & 136) == 8) ? 127 : 255;
        }
    }
    default_clut.clut256[i] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
}
}
