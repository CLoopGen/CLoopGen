#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried RAW dependency using induction variable with memory access
    int prev = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                int index = (prev + cbp_chroma_block[i][j][k]) % 16; // RAW: prev used before update
                if (cbp_chroma_block[i][(index / 4) % 4][index % 4]) // Introduces data-dependent indexing
                    cr_cbp = 2;
                prev = index + 1; // Loop-carried dependency: current depends on prior iteration
            }
        }
    }
}
