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
    int found_first = 0;
    for (int k = 0; k < npart_l_orig && !found_first; k++) {
        if (s3_l[i][k] != 0.) {
            s3ind[i][0] = k;
            found_first = 1;
        }
    }
    if (!found_first) {
        s3ind[i][0] = npart_l_orig - 1;
    }
    int found_last = 0;
    for (int k = npart_l_orig - 1; k >= 0 && !found_last; k--) {
        if (s3_l[i][k] != 0.) {
            s3ind[i][1] = k;
            found_last = 1;
        }
    }
    if (!found_last) {
        s3ind[i][1] = 0;
    }
}
}
