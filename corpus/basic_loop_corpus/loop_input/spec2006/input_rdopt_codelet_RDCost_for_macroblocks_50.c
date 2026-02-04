#include <inttypes.h>

int cbp_chroma_block[2][4][4];
int i;
int j;
int k;
int cr_cbp;

void init_vars() {
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                cbp_chroma_block[i][j][k] = 1;
            }
        }
    }
    i = 0;
    j = 0;
    k = 0;
    cr_cbp = 0;
}