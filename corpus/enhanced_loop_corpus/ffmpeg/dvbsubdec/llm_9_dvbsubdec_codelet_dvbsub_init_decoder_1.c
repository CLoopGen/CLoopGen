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
for (i = 2; i < 128; i++) {
    int j = i * 2;
    if (j < 8) {
        r = (j & 1) ? 255 : 0;
        g = (j & 2) ? 255 : 0;
        b = (j & 4) ? 255 : 0;
        a = 63;
    } else {
        switch (j & 136) {
          case 0:
            r = (j % 3) * 85 + ((j & 16) ? 170 : 0);
            g = ((j + 1) % 3) * 85 + ((j & 32) ? 170 : 0);
            b = ((j + 2) % 3) * 85 + ((j & 64) ? 170 : 0);
            a = 255;
            break;
          case 8:
            r = (j % 3) * 85 + ((j & 16) ? 170 : 0);
            g = ((j + 1) % 3) * 85 + ((j & 32) ? 170 : 0);
            b = ((j + 2) % 3) * 85 + ((j & 64) ? 170 : 0);
            a = 127;
            break;
          case 128:
            r = 127 + (j % 2) * 43 + ((j & 16) ? 85 : 0);
            g = 127 + ((j + 1) % 2) * 43 + ((j & 32) ? 85 : 0);
            b = 127 + ((j + 2) % 2) * 43 + ((j & 64) ? 85 : 0);
            a = 255;
            break;
          case 136:
            r = (j % 2) * 43 + ((j & 16) ? 85 : 0);
            g = ((j + 1) % 2) * 43 + ((j & 32) ? 85 : 0);
            b = ((j + 2) % 2) * 43 + ((j & 64) ? 85 : 0);
            a = 255;
            break;
        }
    }
    default_clut.clut256[j] = (((unsigned int)(a) << 24) | ((r) << 16) | ((g) << 8) | (b));
}
}
