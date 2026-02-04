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
    DCTELEM t0, t1, t2, t3, t4, t5, t6, t7;
    DCTELEM u10, u11, u12, u13;
    DCTELEM v10, v11, v12, v13, v5;

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

    t0 = (((inptr[8 * 0]) * (quantptr[8 * 0])) >> (13 - 1));
    t1 = (((inptr[8 * 2]) * (quantptr[8 * 2])) >> (13 - 1));
    t2 = (((inptr[8 * 4]) * (quantptr[8 * 4])) >> (13 - 1));
    t3 = (((inptr[8 * 6]) * (quantptr[8 * 6])) >> (13 - 1));

    u10 = t0 + t2;
    u11 = t0 - t2;
    u13 = t1 + t3;
    u12 = ((DCTELEM)(((t1 - t3) * (((JLONG)362))) >> (8))) - u13;

    t0 = u10 + u13;
    t3 = u10 - u13;
    t1 = u11 + u12;
    t2 = u11 - u12;

    t4 = (((inptr[8 * 1]) * (quantptr[8 * 1])) >> (13 - 1));
    t5 = (((inptr[8 * 3]) * (quantptr[8 * 3])) >> (13 - 1));
    t6 = (((inptr[8 * 5]) * (quantptr[8 * 5])) >> (13 - 1));
    t7 = (((inptr[8 * 7]) * (quantptr[8 * 7])) >> (13 - 1));

    v13 = t6 + t5;
    v10 = t6 - t5;
    v11 = t4 + t7;
    v12 = t4 - t7;

    t7 = v11 + v13;
    v11 = ((DCTELEM)(((v11 - v13) * (((JLONG)362))) >> (8)));
    v5 = ((DCTELEM)(((v10 + v12) * (((JLONG)473))) >> (8)));

    v10 = ((DCTELEM)(((v12) * (((JLONG)277))) >> (8))) - v5;
    v12 = ((DCTELEM)(((v10) * (-((JLONG)669))) >> (8))) + v5;

    t6 = v12 - t7;
    t5 = v11 - t6;
    t4 = v10 + t5;

    wsptr[8 * 0] = (int)(t0 + t7);
    wsptr[8 * 7] = (int)(t0 - t7);
    wsptr[8 * 1] = (int)(t1 + t6);
    wsptr[8 * 6] = (int)(t1 - t6);
    wsptr[8 * 2] = (int)(t2 + t5);
    wsptr[8 * 5] = (int)(t2 - t5);
    wsptr[8 * 4] = (int)(t3 + t4);
    wsptr[8 * 3] = (int)(t3 - t4);

    inptr++;
    quantptr++;
    wsptr++;
}
}
