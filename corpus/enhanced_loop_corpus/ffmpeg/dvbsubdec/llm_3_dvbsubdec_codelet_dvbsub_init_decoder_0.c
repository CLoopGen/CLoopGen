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
    // Variant 2: Strided memory access in reverse order with stride of -2 (indirect indexing)
    uint32_t *clut = default_clut.clut16;
    for (i = 15; i >= 1; i -= 2) {  // Stride -2, accessing odd indices descending
        if (i < 8) {
            r = (i & 1) ? 255 : 0;
            g = (i & 2) ? 255 : 0;
            b = (i & 4) ? 255 : 0;
        } else {
            r = (i & 1) ? 127 : 0;
            g = (i & 2) ? 127 : 0;
            b = (i & 4) ? 127 : 0;
        }
        clut[i] = (((unsigned int)(255) << 24) | ((r) << 16) | ((g) << 8) | (b));
    }
    // Fill skipped even indices in a second forward pass with +2 stride
    for (i = 2; i < 16; i += 2) {
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
