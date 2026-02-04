#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int i;
int top;
unsigned int lb;
unsigned int rb;
unsigned long *t;
unsigned long *f;
unsigned long l;
unsigned long m;
unsigned long mask;

void init_vars() {
    top = 131072; // Approximately 128KB of data for f and t arrays (each unsigned long is 8 bytes)
    lb = 3;
    rb = 5;
    mask = 0xFFFFFFFFUL;
    l = 0x12345678UL;

    f = (unsigned long*)malloc(top * sizeof(unsigned long));
    t = (unsigned long*)malloc(top * sizeof(unsigned long));

    for (int idx = 0; idx < top; idx++) {
        f[idx] = 0xABCDEF00UL + idx;
    }
}