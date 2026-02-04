#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

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
        quantptr_base[i] = (ISLOW_MULT_TYPE)(i % 64 + 1);
        wsptr_base[i] = 0;
    }

    inptr = inptr_base + 8 * 0;
    quantptr = quantptr_base + 8 * 0;
    wsptr = wsptr_base + 8 * 0;
}