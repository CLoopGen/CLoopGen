#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 s3_s[64][64];
extern int npart_s;
extern int s3ind_s[63][2];
extern int b;
extern int k;
extern FLOAT8 SNR_s[63];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (b = 0; b < npart_s; b++) {
    FLOAT8 norm = 0;
    int start_idx = s3ind_s[b][0];
    int end_idx = s3ind_s[b][1];
    for (k = start_idx; k <= end_idx; k++) {
        norm += s3_s[b][k];
    }
    FLOAT8 factor = SNR_s[b] / norm;
    for (k = start_idx; k <= end_idx; k++) {
        s3_s[b][k] *= factor;
    }
}
}
