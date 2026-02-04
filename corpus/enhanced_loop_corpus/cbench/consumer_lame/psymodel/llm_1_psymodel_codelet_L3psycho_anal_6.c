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
    int found_start = 0;
    int found_end = 0;
    for (int k = 0, m = npart_s_orig - 1; !found_start || !found_end; k++, m--) {
        if (!found_start && k < npart_s_orig) {
            if (s3_s[i][k] != 0.) {
                s3ind_s[i][0] = k;
                found_start = 1;
            }
        }
        if (!found_end && m >= 0) {
            if (s3_s[i][m] != 0.) {
                s3ind_s[i][1] = m;
                found_end = 1;
            }
        }
    }
    if (!found_start) s3ind_s[i][0] = npart_s_orig;
    if (!found_end) s3ind_s[i][1] = -1;
}
}
