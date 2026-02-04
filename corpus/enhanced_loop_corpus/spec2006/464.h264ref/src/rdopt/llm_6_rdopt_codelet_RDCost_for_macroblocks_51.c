#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_cbp = cr_cbp; // Local accumulator to remove direct write on each iteration
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                if (cbp_chroma_block[i][j][k])
                    temp_cbp |= 2; // Introduce WAW dependency via cumulative update
    cr_cbp = temp_cbp; // Single write outside loops to eliminate loop-carried dependence on cr_cbp
}
