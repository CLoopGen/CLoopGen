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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t base_val = 255 << 24;
    int prev_i = 1;
    r = 0; g = 0; b = 0;
    for (i = 1; i < 16; i++) {
        int offset = i - prev_i;
        if (offset == 0) offset = 1;
        if (i < 8) {
            r = ((i & 1) ? 255 : 0);
            g = ((i & 2) ? 255 : 0);
            b = ((i & 4) ? 255 : 0);
        } else {
            r = ((i & 1) ? 127 : 0) + ((r >> 1) & 0x7F); // Introduce WAW and RAW dependency on previous r
            g = ((i & 2) ? 127 : 0) + ((g >> 1) & 0x7F);
            b = ((i & 4) ? 127 : 0) + ((b >> 1) & 0x7F);
        }
        default_clut.clut16[i] = base_val | (r << 16) | (g << 8) | b;
        prev_i = i;
    }
}
