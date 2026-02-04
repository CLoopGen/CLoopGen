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
    int temp_r, temp_g, temp_b, temp_a;
    for (i = 1; i < 256; i++) {
        temp_r = 0; temp_g = 0; temp_b = 0; temp_a = 0;
        if (i < 8) {
            temp_r = (i & 1) ? 255 : 0;
            temp_g = (i & 2) ? 255 : 0;
            temp_b = (i & 4) ? 255 : 0;
            temp_a = 63;
        } else {
            switch (i & 136) {
              case 0:
                temp_r = ((i & 1) ? 85 : 0) + ((i & 16) ? 170 : 0);
                temp_g = ((i & 2) ? 85 : 0) + ((i & 32) ? 170 : 0);
                temp_b = ((i & 4) ? 85 : 0) + ((i & 64) ? 170 : 0);
                temp_a = 255;
                break;
              case 8:
                temp_r = ((i & 1) ? 85 : 0) + ((i & 16) ? 170 : 0);
                temp_g = ((i & 2) ? 85 : 0) + ((i & 32) ? 170 : 0);
                temp_b = ((i & 4) ? 85 : 0) + ((i & 64) ? 170 : 0);
                temp_a = 127;
                break;
              case 128:
                temp_r = 127 + ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
                temp_g = 127 + ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
                temp_b = 127 + ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
                temp_a = 255;
                break;
              case 136:
                temp_r = ((i & 1) ? 43 : 0) + ((i & 16) ? 85 : 0);
                temp_g = ((i & 2) ? 43 : 0) + ((i & 32) ? 85 : 0);
                temp_b = ((i & 4) ? 43 : 0) + ((i & 64) ? 85 : 0);
                temp_a = 255;
                break;
            }
        }
        r = temp_r; g = temp_g; b = temp_b; a = temp_a;
        default_clut.clut256[i] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
    }
}
