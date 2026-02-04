#include <stdio.h>

extern  int dims[3][3];
extern  int xstart[3];
extern  int ystart[3];
extern  int zstart[3];
extern int indexmap[128][256][256];
extern int i;
extern int j;
extern int k;
extern int ii;
extern int ii2;
extern int jj;
extern int ij2;
extern int kk;



void loop(){
// Reverse loop order to change data access pattern and introduce new loop-carried dependencies
for (k = dims[2][2] - 1; k >= 0; k--) {
    kk = (k + 1 + zstart[2] - 2 + 128 / 2) % 128 - 128 / 2;
    int temp_kk_sq = kk * kk;
    for (j = dims[2][1] - 1; j >= 0; j--) {
        jj = (j + 1 + ystart[2] - 2 + 256 / 2) % 256 - 256 / 2;
        int temp_jj_sq = jj * jj;
        for (i = dims[2][0] - 1; i >= 0; i--) {
            ii = (i + 1 + xstart[2] - 2 + 256 / 2) % 256 - 256 / 2;
            int temp_ii_sq = ii * ii;
            int temp_sum = temp_kk_sq + temp_jj_sq + temp_ii_sq;
            indexmap[k][j][i] = temp_sum;
        }
    }
}
}
