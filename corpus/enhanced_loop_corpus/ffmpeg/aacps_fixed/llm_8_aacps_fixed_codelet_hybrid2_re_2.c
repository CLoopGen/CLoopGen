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
for (i = 0; i < len; i++, in++) {
    INT64FLOAT re_in = (int)(((int64_t)(filter[6]) * (in[6][0]) + 1073741824) >> 31);
    INT64FLOAT im_in = (int)(((int64_t)(filter[6]) * (in[6][1]) + 1073741824) >> 31);
    INT64FLOAT re_op = 0;
    INT64FLOAT im_op = 0;

    for (j = 1; j < 6; j += 2) {
        int k = 12 - j - 1;
        re_op += (INT64FLOAT)filter[j] * (in[j][0] + in[k][0]);
        im_op += (INT64FLOAT)filter[j] * (in[j][1] + in[k][1]);
    }

    re_op = (re_op + 1073741824) >> 31;
    im_op = (im_op + 1073741824) >> 31;

    INTFLOAT re_sum = (INTFLOAT)(re_in + re_op);
    INTFLOAT im_sum = (INTFLOAT)(im_in + im_op);
    INTFLOAT re_diff = (INTFLOAT)(re_in - re_op);
    INTFLOAT im_diff = (INTFLOAT)(im_in - im_op);

    out[reverse][i][0] = re_sum;
    out[reverse][i][1] = im_sum;
    out[!reverse][i][0] = re_diff;
    out[!reverse][i][1] = im_diff;
}
}
