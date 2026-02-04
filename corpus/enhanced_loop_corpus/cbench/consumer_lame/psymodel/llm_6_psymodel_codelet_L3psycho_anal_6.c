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
    int k;
    for (i = 0; i < npart_s; i++) {
        j = 0;
        for (k = 0; k < npart_s_orig; k++) {
            if (s3_s[i][k] != 0.) {
                j = k;
                break;
            }
        }
        s3ind_s[i][0] = j;
        j = npart_s_orig - 1;
        for (k = npart_s_orig - 1; k >= 0; k--) {
            if (s3_s[i][k] != 0.) {
                j = k;
                break;
            }
        }
        s3ind_s[i][1] = j;
    }
}
