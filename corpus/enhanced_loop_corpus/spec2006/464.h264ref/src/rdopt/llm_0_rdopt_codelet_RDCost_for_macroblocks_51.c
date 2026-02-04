#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int idx_i = i / 4;
        int idx_j = (i % 4) / 2;
        int idx_k = i % 2;
        if (idx_i < 2 && idx_j < 4 && idx_k < 4)
            if (cbp_chroma_block[idx_i][idx_j][idx_k])
                cr_cbp = 2;
    }
}
