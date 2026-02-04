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
    int found_first = 0;
    for (j = 0; j < npart_s_orig && !found_first; j++) {
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][0] = j;
            found_first = 1;
        }
    }
    if (!found_first) {
        s3ind_s[i][0] = npart_s_orig;
    }

    int found_last = 0;
    for (j = npart_s_orig - 1; j >= 0 && !found_last; j--) {
        if (s3_s[i][j] != 0.) {
            s3ind_s[i][1] = j;
            found_last = 1;
        }
    }
    if (!found_last) {
        s3ind_s[i][1] = -1;
    }
}
}
