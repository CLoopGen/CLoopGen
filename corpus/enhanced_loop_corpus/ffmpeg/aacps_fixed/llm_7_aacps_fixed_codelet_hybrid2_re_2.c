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
INT64FLOAT prev_re_in = 0, prev_im_in = 0;
for (i = 0; i < len; i++ , in++) {
    INT64FLOAT re_in = (int)(((int64_t)(filter[6]) * (in[6][0]) + 1073741824) >> 31);
    INT64FLOAT im_in = (int)(((int64_t)(filter[6]) * (in[6][1]) + 1073741824) >> 31);
    INT64FLOAT re_op = 0.F;
    INT64FLOAT im_op = 0.F;

    for (j = 0; j < 6; j += 2) {
        int tap = filter[j + 1];
        int in_re1 = in[j + 1][0], in_re2 = in[12 - j - 1][0];
        int in_im1 = in[j + 1][1], in_im2 = in[12 - j - 1][1];
        re_op += (INT64FLOAT)tap * (in_re1 + in_re2);
        im_op += (INT64FLOAT)tap * (in_im1 + in_im2);
    }

    re_op = (re_op + 1073741824) >> 31;
    im_op = (im_op + 1073741824) >> 31;

    INTFLOAT re_val = (INTFLOAT)(re_in + re_op);
    INTFLOAT im_val = (INTFLOAT)(im_in + im_op);

    if (i > 0) {
        re_val = (INTFLOAT)((INT64FLOAT)re_val + prev_re_in) >> 1;
        im_val = (INTFLOAT)((INT64FLOAT)im_val + prev_im_in) >> 1;
    }

    out[reverse][i][0] = re_val;
    out[reverse][i][1] = im_val;
    out[!reverse][i][0] = (INTFLOAT)(re_in - re_op);
    out[!reverse][i][1] = (INTFLOAT)(im_in - im_op);

    prev_re_in = re_in;
    prev_im_in = im_in;
}
}
