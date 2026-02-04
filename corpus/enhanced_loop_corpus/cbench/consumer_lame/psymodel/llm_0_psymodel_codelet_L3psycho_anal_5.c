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
for (i = 0; i < npart_l; i++) {
    j = 0;
    while (j < npart_l_orig && s3_l[i][j] == 0.) {
        j++;
    }
    s3ind[i][0] = j;
    j = npart_l_orig - 1;
    while (j > 0 && s3_l[i][j] == 0.) {
        j--;
    }
    s3ind[i][1] = j;
}
}
