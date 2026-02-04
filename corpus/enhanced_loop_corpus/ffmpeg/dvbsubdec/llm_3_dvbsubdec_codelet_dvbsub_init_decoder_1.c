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
    // Variant 2: Indirect memory access using a precomputed index array to simulate non-sequential write order
    // This variant introduces an auxiliary array of indices accessed indirectly, changing the store pattern to non-linear.
    static int indices[255];
    // Initialize indirect access indices: reverse order for distinct access pattern
    for (int k = 0; k < 255; k++) {
        indices[k] = 255 - k;  // maps 0->255, 1->254, ..., 254->1
    }

    for (i = 0; i < 255; i++) {
        int idx = indices[i];  // indirect indexing

        if (idx < 8) {
            r = (idx & 1) ? 255 : 0;
            g = (idx & 2) ? 255 : 0;
            b = (idx & 4) ? 255 : 0;
            a = 63;
        } else {
            switch (idx & 136) {
              case 0:
                r = ((idx & 1) ? 85 : 0) + ((idx & 16) ? 170 : 0);
                g = ((idx & 2) ? 85 : 0) + ((idx & 32) ? 170 : 0);
                b = ((idx & 4) ? 85 : 0) + ((idx & 64) ? 170 : 0);
                a = 255;
                break;
              case 8:
                r = ((idx & 1) ? 85 : 0) + ((idx & 16) ? 170 : 0);
                g = ((idx & 2) ? 85 : 0) + ((idx & 32) ? 170 : 0);
                b = ((idx & 4) ? 85 : 0) + ((idx & 64) ? 170 : 0);
                a = 127;
                break;
              case 128:
                r = 127 + ((idx & 1) ? 43 : 0) + ((idx & 16) ? 85 : 0);
                g = 127 + ((idx & 2) ? 43 : 0) + ((idx & 32) ? 85 : 0);
                b = 127 + ((idx & 4) ? 43 : 0) + ((idx & 64) ? 85 : 0);
                a = 255;
                break;
              case 136:
                r = ((idx & 1) ? 43 : 0) + ((idx & 16) ? 85 : 0);
                g = ((idx & 2) ? 43 : 0) + ((idx & 32) ? 85 : 0);
                b = ((idx & 4) ? 43 : 0) + ((idx & 64) ? 85 : 0);
                a = 255;
                break;
            }
        }
        default_clut.clut256[idx] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
    }
}
