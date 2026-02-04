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
int stride = 2;
for (i = 0; i < dims[2][0]; i += stride) {
    for (j = 0; j < dims[2][1]; j += stride) {
        for (k = 0; k < dims[2][2]; k += stride) {
            ii = (i + 1 + xstart[2] - 2 + 128) % 256 - 128;
            jj = (j + 1 + ystart[2] - 2 + 128) % 256 - 128;
            kk = (k + 1 + zstart[2] - 2 + 64) % 128 - 64;
            int val = kk * kk + jj * jj + ii * ii;
            indexmap[k][j][i] = val;
            if (i+1 < dims[2][0]) indexmap[k][j][i+1] = val;
            if (j+1 < dims[2][1]) indexmap[k][j+1][i] = val;
            if (k+1 < dims[2][2]) indexmap[k+1][j][i] = val;
        }
    }
}
}
