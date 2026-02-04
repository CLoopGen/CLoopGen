#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = npal - 1;
    for (i = 0; i < npal; i++, j--)
        palette[j] = ff_cga_palette[cga_mode45_index[0][i]];
}
