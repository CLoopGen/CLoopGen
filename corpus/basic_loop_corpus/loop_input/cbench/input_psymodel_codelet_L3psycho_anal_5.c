#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 s3_l[64][64];
int npart_l;
int npart_l_orig;
int s3ind[63][2];
int i;
int j;

void init_vars() {
    npart_l = 64;
    npart_l_orig = 64;

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            s3_l[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < 63; i++) {
        s3ind[i][0] = 0;
        s3ind[i][1] = 0;
    }

    i = 0;
    j = 0;
}