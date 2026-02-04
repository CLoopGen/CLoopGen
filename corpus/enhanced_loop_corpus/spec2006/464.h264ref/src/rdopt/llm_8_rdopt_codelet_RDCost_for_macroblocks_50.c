#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    cr_cbp = 0;
    for (i = 0; i < 2; i++) {
        int local_update = 0;
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (cbp_chroma_block[i][j][k]) {
                    local_update = 2;
                }
            }
        }
        if (local_update) {
            cr_cbp = 2;
        }
    }
}
