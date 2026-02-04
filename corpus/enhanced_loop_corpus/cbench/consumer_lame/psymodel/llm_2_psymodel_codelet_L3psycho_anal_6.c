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
    for (int k = 0; k < npart_s_orig; k++) {
        j = k; // Sequential consecutive access pattern
        if (!found_start && s3_s[i][j] != 0.) {
            s3ind_s[i][0] = j;
            found_start = 1;
        }
    }
    if (!found_start) {
        s3ind_s[i][0] = npart_s_orig - 1;
    }
    int found_end = 0;
    for (int k = 0; k < npart_s_orig; k++) {
        j = npart_s_orig - 1 - k; // Reverse consecutive access
        if (!found_end && s3_s[i][j] != 0.) {
            s3ind_s[i][1] = j;
            found_end = 1;
        }
    }
    if (!found_end) {
        s3ind_s[i][1] = 0;
    }
}
}
