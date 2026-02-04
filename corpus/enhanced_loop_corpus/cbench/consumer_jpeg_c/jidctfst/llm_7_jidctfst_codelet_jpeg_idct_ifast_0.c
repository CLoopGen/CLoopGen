#include <stdio.h>

#include <inttypes.h>

typedef int DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int IFAST_MULT_TYPE;

typedef long INT32;

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
DCTELEM temp_storage[8][8]; // Introduce local storage to break loop-carried dependencies
int idx = 0;

for (ctr = 8; ctr > 0; ctr--, idx++) {
    DCTELEM t0, t1, t2, t3, t4, t5, t6, t7;
    DCTELEM t10, t11, t12, t13;
    DCTELEM z5, z10, z11, z12, z13;

    if ((inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
        int dcval = (int)(((IFAST_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        for (int i = 0; i < 8; i++) {
            temp_storage[idx][i] = dcval;
        }
        inptr++;
        quantptr++;
        continue;
    }

    t0 = (((IFAST_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    t1 = (((IFAST_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    t2 = (((IFAST_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    t3 = (((IFAST_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

    t10 = t0 + t2;
    t11 = t0 - t2;
    t13 = t1 + t3;
    t12 = ((DCTELEM)(((t1 - t3) * (((INT32)362))) >> (8))) - t13;

    t0 = t10 + t13;
    t3 = t10 - t13;
    t1 = t11 + t12;
    t2 = t11 - t12;

    t4 = (((IFAST_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    t5 = (((IFAST_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    t6 = (((IFAST_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    t7 = (((IFAST_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    z13 = t6 + t5;
    z10 = t6 - t5;
    z11 = t4 + t7;
    z12 = t4 - t7;

    t7 = z11 + z13;
    t11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> (8)));
    z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> (8)));
    t10 = ((DCTELEM)(((z12) * (((INT32)277))) >> (8))) - z5;
    t12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> (8))) + z5;

    t6 = t12 - t7;
    t5 = t11 - t6;
    t4 = t10 + t5;

    temp_storage[idx][0] = (int)(t0 + t7);
    temp_storage[idx][7] = (int)(t0 - t7);
    temp_storage[idx][1] = (int)(t1 + t6);
    temp_storage[idx][6] = (int)(t1 - t6);
    temp_storage[idx][2] = (int)(t2 + t5);
    temp_storage[idx][5] = (int)(t2 - t5);
    temp_storage[idx][4] = (int)(t3 + t4);
    temp_storage[idx][3] = (int)(t3 - t4);

    inptr++;
    quantptr++;
}

// Write back all results at once to eliminate loop-carried output dependency
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        wsptr[i * 8 + j] = temp_storage[i][j];
    }
}
}
