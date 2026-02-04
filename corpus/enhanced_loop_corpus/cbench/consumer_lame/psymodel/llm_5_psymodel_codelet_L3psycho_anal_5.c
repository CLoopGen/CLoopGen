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
    int found = 0;
    for (j = 0; j < npart_l_orig && !found; j++) {
        if (s3_l[i][j] != 0.) {
            s3ind[i][0] = j;
            found = 1;
        }
    }
    if (!found) {
        s3ind[i][0] = npart_l_orig;
    }

    found = 0;
    for (j = npart_l_orig - 1; j >= 0 && !found; j--) {
        if (s3_l[i][j] != 0.) {
            s3ind[i][1] = j;
            found = 1;
        }
    }
    if (!found) {
        s3ind[i][1] = -1;
    }
}
}
