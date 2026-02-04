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
    r = g = b = a = 0;
    if (i < 8) {
        r = (i & 1) ? 255 : 0;
        g = (i & 2) ? 255 : 0;
        b = (i & 4) ? 255 : 0;
        a = 63;
    } else if ((i & 136) == 0 || (i & 136) == 8) {
        int base_r = (i & 1) ? 85 : 0;
        int base_g = (i & 2) ? 85 : 0;
        int base_b = (i & 4) ? 85 : 0;
        r = base_r + ((i & 16) ? 170 : 0);
        g = base_g + ((i & 32) ? 170 : 0);
        b = base_b + ((i & 64) ? 170 : 0);
        a = (i & 136) == 0 ? 255 : 127;
    } else if ((i & 136) == 128) {
        r = 127 + ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
        g = 127 + ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
        b = 127 + ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
        a = 255;
    } else if ((i & 136) == 136) {
        r = ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
        g = ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
        b = ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
        a = 255;
    }
    default_clut.clut256[i] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
}
}
