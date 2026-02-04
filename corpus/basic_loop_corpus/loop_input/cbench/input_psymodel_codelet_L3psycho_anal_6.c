#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 s3_s[64][64];
int npart_s = 64;
int npart_s_orig = 64;
int s3ind_s[63][2];
int i;
int j;

void init_vars() {
    for (int i0 = 0; i0 < 64; i0++) {
        for (int j0 = 0; j0 < 64; j0++) {
            if (i0 == j0 || i0 == j0 + 1)
                s3_s[i0][j0] = 1.0;
            else
                s3_s[i0][j0] = 0.0;
        }
    }
    npart_s = 64;
    npart_s_orig = 64;
}