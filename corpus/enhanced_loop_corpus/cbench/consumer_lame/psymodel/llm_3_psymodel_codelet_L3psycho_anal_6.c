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
    int stride = 1;
    int start_idx = 0;
    int end_idx = 0;
    int accessed_indices[64];
    int access_count = 0;

    // Strided memory access: traverse with stride of 2, then fill gaps
    for (int k = 0; k < npart_s_orig; k += stride * 2) {
        accessed_indices[access_count++] = k;
    }
    for (int k = stride; k < npart_s_orig; k += stride * 2) {
        accessed_indices[access_count++] = k;
    }

    // Forward scan using strided access order
    s3ind_s[i][0] = npart_s_orig - 1;
    for (int idx = 0; idx < access_count; idx++) {
        j = accessed_indices[idx];
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][0] = j;
            break;
        }
    }

    // Backward scan using reverse strided access order
    s3ind_s[i][1] = 0;
    for (int idx = access_count - 1; idx >= 0; idx--) {
        j = accessed_indices[idx];
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][1] = j;
            break;
        }
    }
}
}
