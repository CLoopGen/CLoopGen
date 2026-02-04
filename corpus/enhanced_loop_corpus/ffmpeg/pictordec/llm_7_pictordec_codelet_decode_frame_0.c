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
    int j;
    for (i = 0, j = npal - 1; i < npal; i++, j--) {
        if (j >= i) {
            palette[i] = ff_cga_palette[cga_mode45_index[idx][i]];
            if (j != i) {
                palette[j] = ff_cga_palette[cga_mode45_index[idx][j]];
            }
        }
    }
}
