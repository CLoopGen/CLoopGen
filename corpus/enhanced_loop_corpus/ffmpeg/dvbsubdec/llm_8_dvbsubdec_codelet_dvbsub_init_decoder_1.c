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
for (i = 1; i < 512; i += 2) {
    if (i < 8) {
        r = (i & 1) ? 255 : 0;
        g = (i & 2) ? 255 : 0;
        b = (i & 4) ? 255 : 0;
        a = 63;
    } else {
        int mask = i & 136;
        r = ((i & 1) ? 85 : 0) + ((i & 16) ? 170 : 0);
        g = ((i & 2) ? 85 : 0) + ((i & 32) ? 170 : 0);
        b = ((i & 4) ? 85 : 0) + ((i & 64) ? 170 : 0);
        a = (mask == 8) ? 127 : ((mask == 128 || mask == 136) ? 255 : 255);
        if (mask == 128) {
            r = 127 + ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
            g = 127 + ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
            b = 127 + ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
        } else if (mask == 136) {
            r = ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
            g = ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
            b = ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
        }
    }
    default_clut.clut256[i] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
}
}
