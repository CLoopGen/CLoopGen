#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpcf[16];
extern int order;
extern int i;
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.0F / 4096.F;
    int limit = order > 16 ? 16 : order;
    for (i = 0; i < limit; i++) {
        float val = lpc[i];
        lpcf[i] = val * scale;
    }
}
