#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
INT32 z2;
INT32 z3;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF)) // ~64MB of input data

static JCOEF *inptr_base;
static ISLOW_MULT_TYPE *quantptr_base;
static int *wsptr_base;

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    size_t total_in_size = DATA_SIZE * 8;
    size_t total_quant_size = DATA_SIZE * 8;
    size_t total_wsp_size = DATA_SIZE * 8;

    inptr_base = (JCOEF*)calloc(total_in_size, sizeof(JCOEF));
    quantptr_base = (ISLOW_MULT_TYPE*)calloc(total_quant_size, sizeof(ISLOW_MULT_TYPE));
    wsptr_base = (int*)calloc(total_wsp_size, sizeof(int));

    if (!inptr_base || !quantptr_base || !wsptr_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_in_size; i++) {
        inptr_base[i] = (JCOEF)(i % 257 - 128);
    }

    for (size_t i = 0; i < total_quant_size; i++) {
        quantptr_base[i] = (ISLOW_MULT_TYPE)(i % 65536);
    }

    inptr = inptr_base;
    quantptr = quantptr_base;
    wsptr = wsptr_base;
}