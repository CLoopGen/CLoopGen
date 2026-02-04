#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp10;
JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
INT32 *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure sufficient runtime

static JCOEF inbuf[DATA_SIZE];
static ISLOW_MULT_TYPE quantbuf[DATA_SIZE];
static INT32 wsbuf[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf[i] = (JCOEF)(i % 32768);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 65536);
        wsbuf[i] = 0;
    }
    
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
    ctr = 0;
}