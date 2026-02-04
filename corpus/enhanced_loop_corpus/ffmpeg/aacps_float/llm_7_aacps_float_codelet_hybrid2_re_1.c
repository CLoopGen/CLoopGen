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
    for (i = 0; i < len; i++, in++) {
        // Eliminate partial data dependencies by precomputing symmetric inputs
        INT64FLOAT re_terms[3], im_terms[3];
        
        for (j = 0; j < 6; j += 2) {
            int idx = j / 2;
            int read_idx1 = j + 1;
            int read_idx2 = 12 - j - 1;
            INT64FLOAT filter_val = (INT64FLOAT)filter[j + 1];

            // Remove potential RAW hazards by isolating computations
            re_terms[idx] = filter_val * (in[read_idx1][0] + in[read_idx2][0]);
            im_terms[idx] = filter_val * (in[read_idx1][1] + in[read_idx2][1]);
        }

        INT64FLOAT re_op = re_terms[0] + re_terms[1] + re_terms[2];
        INT64FLOAT im_op = im_terms[0] + im_terms[1] + im_terms[2];
        INT64FLOAT re_in = (filter[6]) * (in[6][0]);
        INT64FLOAT im_in = (filter[6]) * (in[6][1]);

        // Break WAR/WAW dependencies by writing to temporaries first, then assign
        INTFLOAT temp_out1_re = (INTFLOAT)(re_in + re_op);
        INTFLOAT temp_out1_im = (INTFLOAT)(im_in + im_op);
        INTFLOAT temp_out2_re = (INTFLOAT)(re_in - re_op);
        INTFLOAT temp_out2_im = (INTFLOAT)(im_in - im_op);

        out[reverse][i][0] = temp_out1_re;
        out[reverse][i][1] = temp_out1_im;
        out[!reverse][i][0] = temp_out2_re;
        out[!reverse][i][1] = temp_out2_im;
    }
}
