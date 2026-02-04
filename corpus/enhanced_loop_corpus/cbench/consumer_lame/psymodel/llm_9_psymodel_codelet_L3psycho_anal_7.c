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
    FLOAT8 norm = 1e-9; // Avoid division by zero with small epsilon
    int start = s3ind_s[b][0];
    int end = s3ind_s[b][1];
    int len = end - start + 1;

    // Unrolled accumulation to increase arithmetic intensity (assuming length is even)
    for (k = start; k <= end - 3; k += 4) {
        norm += s3_s[b][k] + s3_s[b][k+1] + s3_s[b][k+2] + s3_s[b][k+3];
    }
    // Handle remainder
    for (; k <= end; k++) {
        norm += s3_s[b][k];
    }

    FLOAT8 factor = SNR_s[b] / norm;

    // Apply scaling with combined multiplication, reducing repeated division
    for (k = start; k <= end - 3; k += 4) {
        s3_s[b][k]   *= factor;
        s3_s[b][k+1] *= factor;
        s3_s[b][k+2] *= factor;
        s3_s[b][k+3] *= factor;
    }
    for (; k <= end; k++) {
        s3_s[b][k] *= factor;
    }
}
}
