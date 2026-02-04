#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int sum = 0;
            for (k = 0; k < 4; k++) {
                if (i < 2 && cbp_chroma_block[i][j][k]) {
                    sum += (k + j) * cbp_chroma_block[i][j][k];
                }
            }
            if (sum > 0)
                cr_cbp = 3;
        }
    }
}
