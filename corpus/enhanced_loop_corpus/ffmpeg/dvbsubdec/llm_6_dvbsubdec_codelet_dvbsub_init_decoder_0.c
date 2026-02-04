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
    int temp_r[16] = {0}, temp_g[16] = {0}, temp_b[16] = {0};
    for (i = 1; i < 16; i++) {
        if (i < 8) {
            temp_r[i] = (i & 1) ? 255 : 0;
            temp_g[i] = (i & 2) ? 255 : 0;
            temp_b[i] = (i & 4) ? 255 : 0;
        } else {
            temp_r[i] = (i & 1) ? 127 : 0;
            temp_g[i] = (i & 2) ? 127 : 0;
            temp_b[i] = (i & 4) ? 127 : 0;
        }
    }
    for (i = 1; i < 16; i++) {
        r = temp_r[i];
        g = temp_g[i];
        b = temp_b[i];
        default_clut.clut16[i] = (((unsigned int)(255) << 24) | ((r) << 16) | ((g) << 8) | (b));
    }
}
