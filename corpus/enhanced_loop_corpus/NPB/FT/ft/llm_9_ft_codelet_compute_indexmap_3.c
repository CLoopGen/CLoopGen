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
for (i = 0; i < dims[2][0]; i++) {
    ii = (i + xstart[2] - 1 + 128) % 256 - 128;
    ii2 = ii * ii;
    for (j = 0; j < dims[2][1]; j += 2) {
        jj = (j + ystart[2] - 1 + 128) % 256 - 128;
        ij2 = jj * jj + ii2;
        for (k = 0; k < dims[2][2]; k += 2) {
            kk = (k + zstart[2] - 1 + 64) % 128 - 64;
            indexmap[k][j][i] = kk * kk + ij2;
            if (k+1 < dims[2][2]) {
                kk = (k + 1 + zstart[2] - 1 + 64) % 128 - 64;
                indexmap[k+1][j][i] = kk * kk + ij2;
            }
        }
        if (j+1 < dims[2][1]) {
            jj = (j + 1 + ystart[2] - 1 + 128) % 256 - 128;
            ij2 = jj * jj + ii2;
            for (k = 0; k < dims[2][2]; k++) {
                kk = (k + zstart[2] - 1 + 64) % 128 - 64;
                indexmap[k][j+1][i] = kk * kk + ij2;
            }
        }
    }
}
}
