#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1)
    for (j = 0; j < 4; j += 1)
        for (k = 0; k < 4; k += 1)
            if (cbp_chroma_block[i][j][k] > 0 && (j * 4 + k) % 8 < 4)
                cr_cbp = (cr_cbp | 2);
}
