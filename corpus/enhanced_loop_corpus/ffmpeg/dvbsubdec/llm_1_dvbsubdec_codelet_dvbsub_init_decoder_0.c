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
    for (int outer = 1; outer < 16; outer += 4) {
        for (int inner = 0; inner < 4 && (outer + inner) < 16; inner++) {
            i = outer + inner;
            if (i < 8) {
                r = (i & 1) ? 255 : 0;
                g = (i & 2) ? 255 : 0;
                b = (i & 4) ? 255 : 0;
            } else {
                r = (i & 1) ? 127 : 0;
                g = (i & 2) ? 127 : 0;
                b = (i & 4) ? 127 : 0;
            }
            default_clut.clut16[i] = (((unsigned int)(255) << 24) | ((r) << 16) | ((g) << 8) | (b));
        }
    }
}
