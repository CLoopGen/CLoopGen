#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;

JCOEF in_buffer[64 * 32768];  // 128KB input data (enough for ~32k iterations)
ISLOW_MULT_TYPE quant_buffer[64 * 32768];  // Matching quant data
int ws_buffer[64 * 32768];    // Workspace buffer

JCOEFPTR inptr = in_buffer;
ISLOW_MULT_TYPE *quantptr = quant_buffer;
int *wsptr = ws_buffer;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 32768; i++) {
        in_buffer[i] = (JCOEF)(i % 257 - 128);
        quant_buffer[i] = (ISLOW_MULT_TYPE)(i % 65537 - 32768);
        ws_buffer[i] = 0;
    }
}