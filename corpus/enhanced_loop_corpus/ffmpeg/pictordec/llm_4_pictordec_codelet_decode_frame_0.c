#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (npal <= 0) return;
    for (i = 0; i < npal; i++) {
        int index = cga_mode45_index[idx][i];
        palette[i] = ff_cga_palette[index];
    }
}
