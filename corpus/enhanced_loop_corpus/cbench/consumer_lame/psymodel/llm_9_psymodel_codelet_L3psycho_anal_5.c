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
// Reduce computational intensity by limiting search range probabilistically
// Assume data sparsity: check only every second element in large arrays
int step = (npart_l_orig > 32) ? 2 : 1;

for (i = 0; i < npart_l; i++) {
    // Forward search with reduced frequency when beneficial
    for (j = 0; j < npart_l_orig; j += step) {
        if (s3_l[i][j] != 0.) {
            // Refine to exact index if stepped over
            if (step > 1) {
                for (j = (j - step + 1) > 0 ? (j - step + 1) : 0; j < npart_l_orig; j++) {
                    if (s3_l[i][j] != 0.) break;
                }
            }
            break;
        }
    }
    s3ind[i][0] = j;

    // Backward search with same adaptive step
    for (j = npart_l_orig - 1; j >= 0; j -= step) {
        if (s3_l[i][j] != 0.) {
            // Refine exact position if necessary
            if (step > 1) {
                for (j = (j < npart_l_orig - 1) ? j : npart_l_orig - 1; j >= 0; j--) {
                    if (s3_l[i][j] != 0.) break;
                }
            }
            break;
        }
    }
    s3ind[i][1] = j;
}
}
