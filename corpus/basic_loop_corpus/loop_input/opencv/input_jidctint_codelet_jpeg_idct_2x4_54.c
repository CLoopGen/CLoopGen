#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

#define DATA_SIZE (64 * 1024 * 1024)
#define INPTR_SIZE (8 * 4)
#define QUANTPTR_SIZE (8 * 4)
#define WSPTR_SIZE (2 * 4)

static JCOEF inptr_data[INPTR_SIZE];
static ISLOW_MULT_TYPE quantptr_data[QUANTPTR_SIZE];
static INT32 wsptr_data[WSPTR_SIZE];

JCOEFPTR inptr = inptr_data;
ISLOW_MULT_TYPE *quantptr = quantptr_data;
INT32 *wsptr = wsptr_data;
int ctr;

void init_vars() {
    for (int i = 0; i < INPTR_SIZE; i++) {
        inptr_data[i] = (JCOEF)(i % 32768);
    }
    for (int i = 0; i < QUANTPTR_SIZE; i++) {
        quantptr_data[i] = (ISLOW_MULT_TYPE)(i % 65536);
    }
    for (int i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = 0;
    }
    tmp0 = 0;
    tmp2 = 0;
    tmp10 = 0;
    tmp12 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    ctr = 0;
}