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
    if (i >= npart_s) continue;
    for (j = 0; j < npart_s_orig; j++) {
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][0] = j;
            goto next1;
        }
    }
    s3ind_s[i][0] = npart_s_orig; // in case all elements are zero
next1:
    for (j = npart_s_orig - 1; j >= 0; j--) {
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][1] = j;
            goto next2;
        }
    }
    s3ind_s[i][1] = -1; // in case all elements are zero
next2: ;
}
}
