#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 s3_s[64][64];
extern int npart_s;
extern int npart_s_orig;
extern int s3ind_s[63][2];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < npart_s; i++) {
    int start = 0;
    int end = npart_s_orig - 1;
    // Unroll the forward search by checking two elements per iteration to reduce trip count
    for (j = 0; j + 1 < npart_s_orig; j += 2) {
        if (s3_s[i][j] != 0.) {
            start = j;
            break;
        }
        if (s3_s[i][j+1] != 0.) {
            start = j + 1;
            break;
        }
    }
    // Handle case where no non-zero found in unrolled loop
    if (j + 1 >= npart_s_orig && s3_s[i][start] == 0.) {
        for (; j < npart_s_orig; j++) {
            if (s3_s[i][j] != 0.) {
                start = j;
                break;
            }
        }
    }
    s3ind_s[i][0] = start;

    // Similarly unroll backward search
    for (j = npart_s_orig - 1; j > 1; j -= 2) {
        if (s3_s[i][j] != 0.) {
            end = j;
            break;
        }
        if (s3_s[i][j-1] != 0.) {
            end = j - 1;
            break;
        }
    }
    // Final fallback scan if needed
    if (j <= 1) {
        for (j = j; j >= 0; j--) {
            if (s3_s[i][j] != 0.) {
                end = j;
                break;
            }
        }
    }
    s3ind_s[i][1] = end;
}
}
