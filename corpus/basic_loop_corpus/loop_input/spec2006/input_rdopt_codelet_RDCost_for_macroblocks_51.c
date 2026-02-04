#include <stdint.h>

int cbp_chroma_block[2][4][4];
int i;
int j;
int k;
int cr_cbp;

void init_vars() {
    for (int idx_i = 0; idx_i < 2; idx_i++) {
        for (int idx_j = 0; idx_j < 4; idx_j++) {
            for (int idx_k = 0; idx_k < 4; idx_k++) {
                cbp_chroma_block[idx_i][idx_j][idx_k] = (idx_i * 16 + idx_j * 4 + idx_k) % 7 == 0 ? 1 : 0;
            }
        }
    }
    i = 0;
    j = 0;
    k = 0;
    cr_cbp = 0;
}