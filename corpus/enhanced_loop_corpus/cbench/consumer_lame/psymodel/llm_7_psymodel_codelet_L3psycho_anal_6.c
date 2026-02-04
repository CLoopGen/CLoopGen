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
    int temp_start, temp_end;
    for (i = 0; i < npart_s; i++) {
        temp_start = 0;
        temp_end = 0;
        for (j = 0; j < npart_s_orig; j++) {
            if (s3_s[i][j] != 0. && temp_start == 0) {
                temp_start = j + 1; // Store as offset to avoid WAW on first write
            }
        }
        s3ind_s[i][0] = (temp_start == 0) ? 0 : temp_start - 1;

        for (j = npart_s_orig - 1; j >= 0; j--) {
            if (s3_s[i][j] != 0.) {
                temp_end = j + 1; // Eliminate loop-carried dependence by deferring write
                break;
            }
        }
        s3ind_s[i][1] = (temp_end == 0) ? 0 : temp_end - 1;
    }
}
