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
    ii = (i + 1 + xstart[2] - 2 + 256 / 2) % 256 - 256 / 2;
    ii2 = ii * ii;
    for (j = 0; j < dims[2][1]; j++) {
        jj = (j + 1 + ystart[2] - 2 + 256 / 2) % 256 - 256 / 2;
        ij2 = jj * jj + ii2;
        k = 0;
        if (k < dims[2][2]) {
            do {
                kk = (k + 1 + zstart[2] - 2 + 128 / 2) % 128 - 128 / 2;
                indexmap[k][j][i] = kk * kk + ij2;
                k++;
            } while (k < dims[2][2]);
        }
    }
}
}
