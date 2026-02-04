#include <stdio.h>
#include <inttypes.h>

typedef int DCTELEM;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int IFAST_MULT_TYPE;
typedef long INT32;

DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z5;
DCTELEM z10;
DCTELEM z11;
DCTELEM z12;
DCTELEM z13;

short inbuf[64 * 32768];  // 128KB of input data (padded for safety)
IFAST_MULT_TYPE quantbuf[64 * 32768];  // 256KB quantization data
int wsbuf[64 * 32768];   // 1MB workspace

JCOEFPTR inptr;
IFAST_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;

    for (int i = 0; i < 64 * 32768; i++) {
        inbuf[i] = (short)((i * 17) & 0xFF);
        quantbuf[i] = (i % 257) - 128;
        wsbuf[i] = 0;
    }

    ctr = 8;
}