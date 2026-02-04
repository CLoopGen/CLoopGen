#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2 && cr_cbp != 2; i++)
        for (j = 0; j < 4 && cr_cbp != 2; j++)
            for (k = 0; k < 4 && cr_cbp != 2; k++)
                if (cbp_chroma_block[i][j][k])
                    cr_cbp = 2;
}
