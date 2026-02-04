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



void loop() {
    for (ctr = 8; ctr > 0; ctr--) {
        const int indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
        int base_in = 8 * indices[0];
        int offset_pattern[8] = {0, 8, 16, 24, 32, 40, 48, 56};

        if ((inptr[offset_pattern[1]] | inptr[offset_pattern[2]] | inptr[offset_pattern[3]] |
             inptr[offset_pattern[4]] | inptr[offset_pattern[5]] | inptr[offset_pattern[6]] |
             inptr[offset_pattern[7]]) == 0) {
            int dcval = (int)(((IFAST_MULT_TYPE)(inptr[base_in])) * (quantptr[base_in]));
            for (int j = 0; j < 8; j++) {
                wsptr[offset_pattern[j]] = dcval;
            }
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }

        tmp0 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[0]])) * (quantptr[offset_pattern[0]]));
        tmp1 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[2]])) * (quantptr[offset_pattern[2]]));
        tmp2 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[4]])) * (quantptr[offset_pattern[4]]));
        tmp3 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[6]])) * (quantptr[offset_pattern[6]]));

        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;
        tmp13 = tmp1 + tmp3;
        tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((INT32)362))) >> (8))) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[1]])) * (quantptr[offset_pattern[1]]));
        tmp5 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[3]])) * (quantptr[offset_pattern[3]]));
        tmp6 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[5]])) * (quantptr[offset_pattern[5]]));
        tmp7 = (((IFAST_MULT_TYPE)(inptr[offset_pattern[7]])) * (quantptr[offset_pattern[7]]));

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;
        tmp7 = z11 + z13;
        tmp11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> (8)));
        z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> (8)));
        tmp10 = ((DCTELEM)(((z12) * (((INT32)277))) >> (8))) - z5;
        tmp12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> (8))) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        wsptr[offset_pattern[0]] = (int)(tmp0 + tmp7);
        wsptr[offset_pattern[7]] = (int)(tmp0 - tmp7);
        wsptr[offset_pattern[1]] = (int)(tmp1 + tmp6);
        wsptr[offset_pattern[6]] = (int)(tmp1 - tmp6);
        wsptr[offset_pattern[2]] = (int)(tmp2 + tmp5);
        wsptr[offset_pattern[5]] = (int)(tmp2 - tmp5);
        wsptr[offset_pattern[4]] = (int)(tmp3 + tmp4);
        wsptr[offset_pattern[3]] = (int)(tmp3 - tmp4);

        inptr++;
        quantptr++;
        wsptr++;
    }
}
