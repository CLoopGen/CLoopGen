#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp16;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 tmp27;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target 0.01s runtime

static JCOEF *inptr_base;
static ISLOW_MULT_TYPE *quantptr_base;
static int *wsptr_base;

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    inptr_base = (JCOEF*)calloc(DATA_SIZE, sizeof(JCOEF));
    quantptr_base = (ISLOW_MULT_TYPE*)calloc(DATA_SIZE, sizeof(ISLOW_MULT_TYPE));
    wsptr_base = (int*)calloc(DATA_SIZE, sizeof(int));

    if (!inptr_base || !quantptr_base || !wsptr_base) {
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        inptr_base[i] = (JCOEF)(i % 256 - 128);
        quantptr_base[i] = (ISLOW_MULT_TYPE)(i % 256 + 1);
        wsptr_base[i] = 0;
    }

    inptr = inptr_base;
    quantptr = quantptr_base;
    wsptr = wsptr_base;
}