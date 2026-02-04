#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 s3_l[64][64];
extern int npart_l;
extern int npart_l_orig;
extern int s3ind[63][2];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k;
for (i = 0; i < npart_l; i++) {
    s3ind[i][0] = 0;
    s3ind[i][1] = 0;
    for (k = 0; k < npart_l_orig; k++) {
        if (s3_l[i][k] != 0.) {
            s3ind[i][0] = k;
            break;
        }
    }
    for (k = npart_l_orig - 1; k >= 0; k--) {
        if (s3_l[i][k] != 0.) {
            s3ind[i][1] = k;
            break;
        }
    }
}
}
