#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;

#define DATA_SIZE (16 * 1024 * 1024)
#define INPTR_SIZE (8 * 7)
#define QUANTPTR_SIZE (8 * 7)
#define WSPPTR_SIZE (7 * 7)

static JCOEF inptr_data[INPTR_SIZE];
static ISLOW_MULT_TYPE quantptr_data[QUANTPTR_SIZE];
static int wsptr_data[WSPPTR_SIZE];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    for (int i = 0; i < INPTR_SIZE; i++) {
        inptr_data[i] = (JCOEF)(i % 128);
    }
    for (int i = 0; i < QUANTPTR_SIZE; i++) {
        quantptr_data[i] = (ISLOW_MULT_TYPE)(1 + (i % 50));
    }
    for (int i = 0; i < WSPPTR_SIZE; i++) {
        wsptr_data[i] = 0;
    }

    inptr = inptr_data;
    quantptr = quantptr_data;
    wsptr = wsptr_data;
    ctr = 0;
}