#include <stdio.h>
#include <inttypes.h>

typedef unsigned long LONG;

int i;
LONG temp;
LONG A;
LONG B;
LONG C;
LONG D;
LONG E;
LONG W[80];

void init_vars() {
    A = 0x67452301UL;
    B = 0xEFCDAB89UL;
    C = 0x98BADCFEUL;
    D = 0x10325476UL;
    E = 0xC3D2E1F0UL;
    temp = 0UL;

    for (int j = 0; j < 80; ++j) {
        W[j] = (LONG)(j * 0x1234567U);
    }
}