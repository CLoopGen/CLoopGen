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
    int k;
    for (i = 0; i < npart_l; i++) {
        k = 0;
        for (j = 0; j < npart_l_orig; j++) {
            if (s3_l[i][j] != 0. && k == 0) {
                s3ind[i][0] = j;
                k = 1;
            }
        }
        if (k == 0) {
            s3ind[i][0] = npart_l_orig - 1;
        }
        k = 0;
        for (j = npart_l_orig - 1; j >= 0; j--) {
            if (s3_l[i][j] != 0. && k == 0) {
                s3ind[i][1] = j;
                k = 1;
            }
        }
        if (k == 0) {
            s3ind[i][1] = 0;
        }
    }
}
