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
int *idx_base = &indexmap[0][0][0];
int stride_j = 256;
int stride_i = 1;
for (k = 0; k < dims[2][2]; k++) {
    kk = (k + 1 + zstart[2] - 2 + 64) % 128 - 64;
    int kk2 = kk * kk;
    for (j = 0; j < dims[2][1]; j++) {
        jj = (j + 1 + ystart[2] - 2 + 128) % 256 - 128;
        int jj2 = jj * jj;
        for (i = 0; i < dims[2][0]; i++) {
            ii = (i + 1 + xstart[2] - 2 + 128) % 256 - 128;
            int value = jj2 + ii*ii + kk2;
            idx_base[k * stride_j * stride_i + j * stride_j + i] = value;
        }
    }
}
}
