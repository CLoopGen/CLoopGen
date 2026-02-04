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
for (i = 1; i < 32; i++) {
    int shift_r = (i & 1) ? (i < 16 ? 255 : 127) : 0;
    int shift_g = (i & 2) ? (i < 16 ? 255 : 127) : 0;
    int shift_b = (i & 4) ? (i < 16 ? 255 : 127) : 0;
    if (i < 16) {
        default_clut.clut16[i] = ((255U << 24) | (shift_r << 16) | (shift_g << 8) | shift_b);
    }
}
}
