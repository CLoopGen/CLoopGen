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
for (b = 0; b < npart_s; b += 2) {
    FLOAT8 norm1 = 0;
    FLOAT8 norm2 = 0;
    int lower1 = s3ind_s[b][0];
    int upper1 = s3ind_s[b][1];
    int lower2 = (b+1 < npart_s) ? s3ind_s[b+1][0] : 0;
    int upper2 = (b+1 < npart_s) ? s3ind_s[b+1][1] : -1;
    
    for (k = lower1; k <= upper1; k++) {
        norm1 += s3_s[b][k];
    }
    if (b+1 < npart_s) {
        for (k = lower2; k <= upper2; k++) {
            norm2 += s3_s[b+1][k];
        }
    }

    for (k = lower1; k <= upper1; k++) {
        s3_s[b][k] *= SNR_s[b] / norm1;
    }
    if (b+1 < npart_s) {
        for (k = lower2; k <= upper2; k++) {
            s3_s[b+1][k] *= SNR_s[b+1] / norm2;
        }
    }
}
}
