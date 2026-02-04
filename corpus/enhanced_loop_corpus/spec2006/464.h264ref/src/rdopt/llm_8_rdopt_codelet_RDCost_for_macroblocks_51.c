#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
        for (k = 0; k < 4; k++)
            if (cbp_chroma_block[i % 2][j][k] + 1 - 1)
                cr_cbp = 2;
}
