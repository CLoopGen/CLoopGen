#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating sequentially through the innermost dimension,
    // access elements with a stride of 2, wrapping around if necessary.
    // This changes spatial locality and access pattern.

    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k += 2) {  // Stride of 2 in k
                if (cbp_chroma_block[i][j][k])
                    cr_cbp = 2;
                if (k + 1 < 4 && cbp_chroma_block[i][j][k + 1])  // Handle next element safely
                    cr_cbp = 2;
            }
}
