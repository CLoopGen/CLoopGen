#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Flattened Index) Memory Access Pattern
    // Collapse 3D indices into a linear traversal to promote cache-friendly,
    // consecutive memory access. Use integer division and modulus to map index.

    int idx;
    for (idx = 0; idx < 32; idx++) {
        i = idx / 16;           // 2 * 4 * 4 = 32 total elements
        j = (idx % 16) / 4;
        k = (idx % 16) % 4;
        if (cbp_chroma_block[i][j][k])
            cr_cbp = 2;
    }
}
