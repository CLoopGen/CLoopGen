#include <stdio.h>

#include <inttypes.h>

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef float FLOAT_MULT_TYPE;

extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z5;
extern float z10;
extern float z11;
extern float z12;
extern float z13;
extern JCOEFPTR inptr;
extern FLOAT_MULT_TYPE *quantptr;
extern float *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    float dcval = (((float)(inptr[8 * 0])) * (quantptr[8 * 0]));
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
}
}
