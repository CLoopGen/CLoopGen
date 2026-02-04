#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int md5uint;

struct roundtab {
    char k;
    char s;
};

md5uint sintab[64];
struct roundtab roundtab[64];
md5uint a;
md5uint b;
md5uint c;
md5uint d;
md5uint t;
md5uint x[16];
md5uint msk;
int i;

void init_vars() {
    for (int j = 0; j < 64; ++j) {
        sintab[j] = (md5uint)(0x67452301U ^ (j * 0x1234567U));
        roundtab[j].k = (char)(j % 16);
        roundtab[j].s = (char)((j * 7 + 1) % 32);
    }

    for (int j = 0; j < 16; ++j) {
        x[j] = (md5uint)(0xEFCDAB89U + j * 0x98765432U);
    }

    a = 0x67452301U;
    b = 0xEFCDAB89U;
    c = 0x98BADCFEU;
    d = 0x10325476U;
    t = 0;
    msk = 0xFFFFFFFFU;
    i = 0;
}