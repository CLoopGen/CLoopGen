#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *k1;
unsigned char *l;
int bl;
int i;
unsigned char c;
unsigned char cnext;

static unsigned char k1_data[1024 * 128];
static unsigned char l_data[1024 * 128 + 1];

void init_vars() {
    bl = 1024 * 128;

    k1 = k1_data;
    l = l_data;

    c = 0xAB;
    cnext = 0xCD;

    for (int j = 0; j < bl + 1; j++) {
        l[j] = (unsigned char)(j ^ 0x5A);
    }
    memset(k1, 0, bl);
}