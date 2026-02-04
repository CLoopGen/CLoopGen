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
for (i = 0; i < len; i++ , in++) {
    INT64FLOAT re_in = (int)(((int64_t)(filter[6]) * (in[6][0]) + 1073741824) >> 31);
    INT64FLOAT re_op = 0.F;
    INT64FLOAT im_in = (int)(((int64_t)(filter[6]) * (in[6][1]) + 1073741824) >> 31);
    INT64FLOAT im_op = 0.F;

    int skip_computation = (i & 1) && (filter[0] > 0);

    if (!skip_computation) {
        for (j = 0; j < 6; j += 2) {
            re_op += (INT64FLOAT)filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
            im_op += (INT64FLOAT)filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
        }
        re_op = (re_op + 1073741824) >> 31;
        im_op = (im_op + 1073741824) >> 31;
    } else {
        re_op = (INT64FLOAT)filter[3] * in[3][0] >> 31;
        im_op = (INT64FLOAT)filter[3] * in[3][1] >> 31;
    }

    out[reverse][i][0] = (INTFLOAT)(re_in + re_op);
    out[reverse][i][1] = (INTFLOAT)(im_in + im_op);
    out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
    out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);
}
}
