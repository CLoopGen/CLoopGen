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
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
JLONG z5;

JCOEF *inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024)
#define INPTR_SIZE (8 * 8)
#define QUANTPTR_SIZE (8 * 8)
#define WS_SIZE (8 * 16)

static JCOEF in_data[INPTR_SIZE];
static ISLOW_MULT_TYPE quant_data[QUANTPTR_SIZE];
static int ws_data[WS_SIZE];

void init_vars() {
    for (int i = 0; i < INPTR_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 257 - 128);
    }
    for (int i = 0; i < QUANTPTR_SIZE; i++) {
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 257 + 1);
    }
    for (int i = 0; i < WS_SIZE; i++) {
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 0;
}