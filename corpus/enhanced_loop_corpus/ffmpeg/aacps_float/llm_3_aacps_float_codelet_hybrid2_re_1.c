#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float INT64FLOAT;

extern INTFLOAT (*in)[2];
extern INTFLOAT (*out)[32][2];
extern  INTFLOAT filter[8];
extern int len;
extern int reverse;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect addressing via index mapping array
    // Use a precomputed index map to simulate non-linear, strided access patterns
    // This variant enhances data locality control and allows for future extension to arbitrary permutations

    static const int index_map[6] = {1, 3, 5, 7, 9, 11}; // odd indices from original j+1 and symmetric positions
    INTFLOAT (*base_in)[2] = in;

    for (i = 0; i < len; i++) {
        int center = i + 6;
        INT64FLOAT re_in = ((filter[6]) * (base_in[center][0]));
        INT64FLOAT im_in = ((filter[6]) * (base_in[center][1]));
        INT64FLOAT re_op = 0.F;
        INT64FLOAT im_op = 0.F;

        for (j = 0; j < 6; j += 2) {
            int k = index_map[j];  // Indirect access through lookup table
            int sym = i + (12 - (k - i)) - 1;  // Symmetric index relative to window
            re_op += (INT64FLOAT)filter[k - i] * (base_in[k][0] + base_in[sym][0]);
            im_op += (INT64FLOAT)filter[k - i] * (base_in[k][1] + base_in[sym][1]);
        }

        out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
        out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
        out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
        out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
    }
}
