#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF))  // ~64MB of JCOEF data

static JCOEF *inptr_base;
static ISLOW_MULT_TYPE *quantptr_base;
static int *wsptr_base;

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    size_t total_size = DATA_SIZE;

    inptr_base = (JCOEF*)aligned_alloc(32, total_size * sizeof(JCOEF));
    quantptr_base = (ISLOW_MULT_TYPE*)aligned_alloc(32, total_size * sizeof(ISLOW_MULT_TYPE));
    wsptr_base = (int*)aligned_alloc(32, total_size * sizeof(int));

    if (!inptr_base || !quantptr_base || !wsptr_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        inptr_base[i] = (JCOEF)(i % 32767);
        quantptr_base[i] = (ISLOW_MULT_TYPE)(i % 16384);
        wsptr_base[i] = 0;
    }

    inptr = inptr_base;
    quantptr = quantptr_base;
    wsptr = wsptr_base;
}

__attribute__((destructor))
void cleanup() {
    free(inptr_base);
    free(quantptr_base);
    free(wsptr_base);
}