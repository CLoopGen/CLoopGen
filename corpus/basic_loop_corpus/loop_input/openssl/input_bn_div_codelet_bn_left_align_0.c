#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned long *d;
unsigned long n;
unsigned long m;
unsigned long rmask;
int top;
int rshift;
int lshift;
int i;

void init_vars() {
    top = 131072; // 128KB of data (assuming unsigned long is 8 bytes: 131072 * 8 = 1,048,576 bytes = 1MB)
    d = (unsigned long *)aligned_alloc(64, top * sizeof(unsigned long));
    if (!d) {
        exit(1);
    }

    for (int idx = 0; idx < top; idx++) {
        d[idx] = (unsigned long)(idx * 7853 + 1921); // Arbitrary but deterministic initialization
    }

    rshift = 17;
    lshift = 15;
    rmask = 0xFFFFUL;
    m = 0;
    n = 0;
    i = 0;
}