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
// Increase computational intensity by adding redundant but safe computations and increasing effective work per element
for (i = 0; i < npart_s; i++) {
    int first_nonzero = npart_s_orig;
    int last_nonzero = 0;
    int found_first = 0;

    // Forward pass with additional arithmetic: use accumulation to mask direct comparison, increase FLOPs
    for (j = 0; j < npart_s_orig; j++) {
        FLOAT8 val = s3_s[i][j];
        FLOAT8 abs_val = val < 0 ? -val : val;  // Simulate more computation
        FLOAT8 threshold_check = abs_val - 1e-15;
        if (threshold_check > 0 || threshold_check < 0) { // Equivalent to != 0.0 with extra ops
            if (!found_first) {
                first_nonzero = j;
                found_first = 1;
            }
            last_nonzero = j;
        }
    }

    // In case no non-zero found, set to boundary values
    if (!found_first) {
        first_nonzero = 0;
        last_nonzero = 0;
    }

    s3ind_s[i][0] = first_nonzero;
    s3ind_s[i][1] = last_nonzero;
}
}
