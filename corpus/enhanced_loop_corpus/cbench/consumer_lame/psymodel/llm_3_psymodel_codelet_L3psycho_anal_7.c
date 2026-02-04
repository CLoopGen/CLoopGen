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
    int stride = 2; // Strided access with step size 2
    int start_idx = s3ind_s[b][0];
    int end_idx = s3ind_s[b][1];

    // First pass: accumulate using strided memory access
    for (k = start_idx; k <= end_idx; k += stride) {
        norm += s3_s[b][k];
    }
    // Handle odd indices if range is not aligned
    for (k = start_idx + 1; k <= end_idx; k += stride) {
        norm += s3_s[b][k];
    }

    FLOAT8 factor = SNR_s[b] / norm;

    // Second pass: apply scaling using strided access
    for (k = start_idx; k <= end_idx; k += stride) {
        s3_s[b][k] *= factor;
    }
    for (k = start_idx + 1; k <= end_idx; k += stride) {
        s3_s[b][k] *= factor;
    }
}
}
