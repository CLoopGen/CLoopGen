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
    // Variant 1: Consecutive memory access with unrolled loop (partial)
    int indices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    uint32_t *clut = default_clut.clut16;
    for (i = 0; i < 15; i++) {
        int idx = indices[i];
        if (idx < 8) {
            r = (idx & 1) ? 255 : 0;
            g = (idx & 2) ? 255 : 0;
            b = (idx & 4) ? 255 : 0;
        } else {
            r = (idx & 1) ? 127 : 0;
            g = (idx & 2) ? 127 : 0;
            b = (idx & 4) ? 127 : 0;
        }
        clut[idx] = (((unsigned int)(255) << 24) | ((r) << 16) | ((g) << 8) | (b));
    }
}
