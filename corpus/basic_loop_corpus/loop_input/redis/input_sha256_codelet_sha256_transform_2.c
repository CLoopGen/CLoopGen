#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t WORD;

WORD k[64];
WORD a;
WORD b;
WORD c;
WORD d;
WORD e;
WORD f;
WORD g;
WORD h;
WORD i;
WORD t1;
WORD t2;
WORD m[64];

void init_vars() {
    for (i = 0; i < 64; ++i) {
        k[i] = i * 0x3f3f + 0xdeadbeef;
        m[i] = i * 0x1f1f + 0xc0deface;
    }
    a = 0x6a09e667;
    b = 0xbb67ae85;
    c = 0x3c6ef372;
    d = 0xa54ff53a;
    e = 0x510e527f;
    f = 0x9b05688c;
    g = 0x1f83d9ab;
    h = 0x5be0cd19;
    t1 = 0;
    t2 = 0;
}