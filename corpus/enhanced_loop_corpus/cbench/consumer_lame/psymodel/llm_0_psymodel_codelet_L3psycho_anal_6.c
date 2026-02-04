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
    j = 0;
    while (j < npart_s_orig) {
        if (s3_s[i][j] != 0.)
            break;
        j++;
    }
    s3ind_s[i][0] = j;
    j = npart_s_orig - 1;
    while (j > 0) {
        if (s3_s[i][j] != 0.)
            break;
        j--;
    }
    s3ind_s[i][1] = j;
}
}
