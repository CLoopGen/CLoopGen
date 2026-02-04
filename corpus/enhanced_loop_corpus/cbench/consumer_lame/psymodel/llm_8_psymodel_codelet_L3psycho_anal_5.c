#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 s3_l[64][64];
extern int npart_l;
extern int npart_l_orig;
extern int s3ind[63][2];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < npart_l; i++) {
    int start = 0;
    int end = npart_l_orig - 1;
    // Unroll the forward scan by 2x to reduce loop overhead
    for (j = 0; j + 1 < npart_l_orig; j += 2) {
        if (s3_l[i][j] != 0.) {
            start = j;
            goto forward_done;
        }
        if (s3_l[i][j+1] != 0.) {
            start = j+1;
            goto forward_done;
        }
    }
    // Handle remaining element
    if (j < npart_l_orig && s3_l[i][j] == 0.)
        j++;
    if (j >= npart_l_orig)
        j = npart_l_orig; // No non-zero found, set to limit
forward_done:
    s3ind[i][0] = j;

    // Backward loop with unrolling by 2x
    for (j = npart_l_orig - 1; j > 1; j -= 2) {
        if (s3_l[i][j] != 0.) {
            goto backward_done;
        }
        if (s3_l[i][j-1] != 0.) {
            j = j - 1;
            goto backward_done;
        }
    }
    if (j == 1 && s3_l[i][1] != 0.) {
        j = 1;
    } else {
        j = 0; // Fall-through to first element
    }
backward_done:
    s3ind[i][1] = j;
}
}
