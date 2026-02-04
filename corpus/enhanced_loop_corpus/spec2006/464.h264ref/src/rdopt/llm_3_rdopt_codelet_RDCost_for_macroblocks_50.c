#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Loop Reordering for Different Memory Access Pattern (j-k-i order)
    // Original was i-j-k (row-major like). Now traverse k first, then j, then i,
    // leading to more cache-friendly access if data is stored in row-major order.
    for (k = 0; k < 4; k++)
        for (j = 0; j < 4; j++)
            for (i = 0; i < 2; i++)
                if (cbp_chroma_block[i][j][k])
                    cr_cbp = 2;
}
