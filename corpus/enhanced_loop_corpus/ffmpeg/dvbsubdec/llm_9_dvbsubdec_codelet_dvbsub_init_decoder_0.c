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
for (i = 2; i < 16; i += 2) {
    r = (i & 2) ? 255 : 0;
    g = (i & 4) ? 255 : 0;
    b = (i & 8) ? 255 : 0;
    default_clut.clut16[i] = ((255U << 24) | (r << 16) | (g << 8) | b);
    
    // Add additional computation to increase intensity
    default_clut.clut16[i-1] = ((255U << 24) | ((255 - r) << 16) | ((255 - g) << 8) | (255 - b));
}
}
