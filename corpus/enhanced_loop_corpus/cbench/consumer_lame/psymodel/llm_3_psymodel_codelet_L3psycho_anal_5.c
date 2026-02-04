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
    int start_idx = 0;
    int end_idx = npart_l_orig - 1;
    // Strided forward access with step size 2, then fill in gaps if needed
    int temp_first = npart_l_orig;
    for (int k = 0; k < npart_l_orig; k += 2) {
        if (s3_l[i][k] != 0.) {
            temp_first = k;
            break;
        }
    }
    // If no odd-indexed element found in stride, check the odd positions
    if (temp_first == npart_l_orig) {
        for (int k = 1; k < npart_l_orig; k += 2) {
            if (s3_l[i][k] != 0.) {
                temp_first = k;
                break;
            }
        }
    }
    s3ind[i][0] = (temp_first == npart_l_orig) ? npart_l_orig - 1 : temp_first;

    int temp_last = -1;
    for (int k = npart_l_orig - 1; k >= 0; k -= 2) {
        if (s3_l[i][k] != 0.) {
            temp_last = k;
            break;
        }
    }
    if (temp_last == -1) {
        for (int k = npart_l_orig - 2; k >= 0; k -= 2) {
            if (s3_l[i][k] != 0.) {
                temp_last = k;
                break;
            }
        }
    }
    s3ind[i][1] = (temp_last == -1) ? 0 : temp_last;
}
}
