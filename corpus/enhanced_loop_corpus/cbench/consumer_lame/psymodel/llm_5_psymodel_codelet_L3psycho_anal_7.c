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
    int start = s3ind_s[b][0];
    int end = s3ind_s[b][1];

    for (k = start; k <= end; k++) {
        if (s3_s[b][k] >= 0) {
            norm += s3_s[b][k];
        } else {
            continue;
        }
    }

    if (norm != 0) {
        for (k = start; k <= end; k++) {
            if (s3_s[b][k] >= 0) {
                s3_s[b][k] *= SNR_s[b] / norm;
            }
        }
    }
}
}
