#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 s3_s[64][64];
int npart_s;
int s3ind_s[63][2];
int b;
int k;
FLOAT8 SNR_s[63];

void init_vars() {
    npart_s = 63;
    for (b = 0; b < npart_s; b++) {
        s3ind_s[b][0] = 0;
        s3ind_s[b][1] = 63;
        SNR_s[b] = 1.5 + (b * 0.1);
        for (k = s3ind_s[b][0]; k <= s3ind_s[b][1]; k++) {
            s3_s[b][k] = 1.0 + (b * 0.01) + (k * 0.001);
        }
    }
}