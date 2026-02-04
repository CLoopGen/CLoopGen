#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef int64_t INT64FLOAT;

extern INTFLOAT (*in)[2];
extern INTFLOAT (*out)[32][2];
extern  INTFLOAT filter[8];
extern int len;
extern int reverse;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT (*local_in)[2] = in;
    INTFLOAT (*local_out)[32][2] = out;
    const int stride = 2;

    for (i = 0; i < len; i++) {
        INT64FLOAT re_in = (int)(((int64_t)(filter[6]) * (local_in[i + 6][0]) + 1073741824) >> 31);
        INT64FLOAT re_op = 0.F;
        INT64FLOAT im_in = (int)(((int64_t)(filter[6]) * (local_in[i + 6][1]) + 1073741824) >> 31);
        INT64FLOAT im_op = 0.F;

        for (j = 0; j < 6; j += stride) {
            int k = j + 1;
            int mirror = 12 - k;
            re_op += (INT64FLOAT)filter[k] * (local_in[i + k][0] + local_in[i + mirror][0]);
            im_op += (INT64FLOAT)filter[k] * (local_in[i + k][1] + local_in[i + mirror][1]);
        }

        re_op = (re_op + 1073741824) >> 31;
        im_op = (im_op + 1073741824) >> 31;

        local_out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
        local_out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
        local_out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
        local_out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
    }
    in = local_in + len;
}
