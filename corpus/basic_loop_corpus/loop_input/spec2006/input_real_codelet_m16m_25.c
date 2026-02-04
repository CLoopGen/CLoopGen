#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (1 << 20)

unsigned short *c;
unsigned short p[9];
int i;

void init_vars() {
    c = (unsigned short*)malloc(DATA_SIZE * sizeof(unsigned short));
    for (int idx = 0; idx < 9; idx++) {
        p[idx] = (unsigned short)(idx * 3);
    }
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        c[idx] = (unsigned short)(idx + 1);
    }
}