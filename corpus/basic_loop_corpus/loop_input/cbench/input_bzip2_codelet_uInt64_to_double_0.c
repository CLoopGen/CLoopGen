#include <stdio.h>
#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

UInt64 *n;
Int32 i;
double base;
double sum;

static UInt64 n_storage; 

void init_vars() {
    n = &n_storage;
    i = 0;
    base = 1.0;
    sum = 0.0;

    for (int j = 0; j < 8; j++) {
        n->b[j] = (UChar)(j + 1);
    }
}