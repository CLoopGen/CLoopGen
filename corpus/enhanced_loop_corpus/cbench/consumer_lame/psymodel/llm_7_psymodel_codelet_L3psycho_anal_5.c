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
    int prev_j;
    for (i = 0; i < npart_l; i++) {
        prev_j = 0;
        for (j = 0; j < npart_l_orig; j++) {
            if (s3_l[i][j] != 0.) {
                s3ind[i][0] = j;
                prev_j = j;
                break;
            }
        }
        // Introduce WAR dependency by reusing j after inner loop
        j = prev_j;
        for (j = npart_l_orig - 1; j >= 0; j--) {
            if (s3_l[i][j] != 0.) {
                s3ind[i][1] = j;
                break;
            }
        }
        // Create artificial WAW on s3ind[i][1] via temporary
        if (s3ind[i][1] < s3ind[i][0]) {
            s3ind[i][1] = s3ind[i][0];
        }
    }
}
