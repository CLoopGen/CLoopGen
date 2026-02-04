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
int temp_kk, temp_ij2;
for (i = 0; i < dims[2][0]; i++) {
    ii = (i + 1 + xstart[2] - 2 + 256 / 2) % 256 - 256 / 2;
    ii2 = ii * ii;
    for (j = 0; j < dims[2][1]; j++) {
        jj = (j + 1 + ystart[2] - 2 + 256 / 2) % 256 - 256 / 2;
        temp_ij2 = jj * jj + ii2; // Introduce local dependency: ij2 now stored in temp to break potential WAW across outer loops
        for (k = 0; k < dims[2][2]; k++) {
            kk = (k + 1 + zstart[2] - 2 + 128 / 2) % 128 - 128 / 2;
            temp_kk = kk * kk; // Add temporary variable to create local RAW dependency (read after write)
            indexmap[k][j][i] = temp_kk + temp_ij2;
        }
    }
}
}
