#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef JLONG IFAST_MULT_TYPE;

extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern JCOEFPTR inptr;
extern IFAST_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    DCTELEM local_tmp0, local_tmp1, local_tmp2, local_tmp3;
    DCTELEM local_tmp4, local_tmp5, local_tmp6, local_tmp7;
    DCTELEM local_z10, local_z11, local_z12, local_z13, local_z5;
    DCTELEM local_tmp10, local_tmp11, local_tmp12, local_tmp13;

    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        int dcval = (int)(((inptr[8 * 0]) * (quantptr[8 * 0])) >> (13 - 1));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        wsptr[8 * 4] = dcval;
        wsptr[8 * 5] = dcval;
        wsptr[8 * 6] = dcval;
        wsptr[8 * 7] = dcval;
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    local_tmp0 = (((inptr[8 * 0]) * (quantptr[8 * 0])) >> (13 - 1));
    local_tmp2 = (((inptr[8 * 4]) * (quantptr[8 * 4])) >> (13 - 1));
    local_tmp1 = (((inptr[8 * 2]) * (quantptr[8 * 2])) >> (13 - 1));
    local_tmp3 = (((inptr[8 * 6]) * (quantptr[8 * 6])) >> (13 - 1));

    local_tmp10 = local_tmp0 + local_tmp2;
    local_tmp11 = local_tmp0 - local_tmp2;
    local_tmp13 = local_tmp1 + local_tmp3;
    local_tmp12 = ((DCTELEM)(((local_tmp1 - local_tmp3) * (((JLONG)362))) >> (8))) - local_tmp13;

    local_tmp0 = local_tmp10 + local_tmp13;
    local_tmp3 = local_tmp10 - local_tmp13;
    local_tmp1 = local_tmp11 + local_tmp12;
    local_tmp2 = local_tmp11 - local_tmp12;

    local_tmp4 = (((inptr[8 * 1]) * (quantptr[8 * 1])) >> (13 - 1));
    local_tmp7 = (((inptr[8 * 7]) * (quantptr[8 * 7])) >> (13 - 1));
    local_tmp5 = (((inptr[8 * 3]) * (quantptr[8 * 3])) >> (13 - 1));
    local_tmp6 = (((inptr[8 * 5]) * (quantptr[8 * 5])) >> (13 - 1));

    local_z13 = local_tmp6 + local_tmp5;
    local_z10 = local_tmp6 - local_tmp5;
    local_z11 = local_tmp4 + local_tmp7;
    local_z12 = local_tmp4 - local_tmp7;

    local_tmp7 = local_z11 + local_z13;
    local_tmp11 = ((DCTELEM)(((local_z11 - local_z13) * (((JLONG)362))) >> (8)));
    local_z5 = ((DCTELEM)(((local_z10 + local_z12) * (((JLONG)473))) >> (8)));

    local_tmp10 = ((DCTELEM)(((local_z12) * (((JLONG)277))) >> (8))) - local_z5;
    local_tmp12 = ((DCTELEM)(((local_z10) * (-((JLONG)669))) >> (8))) + local_z5;

    local_tmp6 = local_tmp12 - local_tmp7;
    local_tmp5 = local_tmp11 - local_tmp6;
    local_tmp4 = local_tmp10 + local_tmp5;

    wsptr[8 * 0] = (int)(local_tmp0 + local_tmp7);
    wsptr[8 * 7] = (int)(local_tmp0 - local_tmp7);
    wsptr[8 * 1] = (int)(local_tmp1 + local_tmp6);
    wsptr[8 * 6] = (int)(local_tmp1 - local_tmp6);
    wsptr[8 * 2] = (int)(local_tmp2 + local_tmp5);
    wsptr[8 * 5] = (int)(local_tmp2 - local_tmp5);
    wsptr[8 * 4] = (int)(local_tmp3 + local_tmp4);
    wsptr[8 * 3] = (int)(local_tmp3 - local_tmp4);

    inptr++;
    quantptr++;
    wsptr++;
}
}
