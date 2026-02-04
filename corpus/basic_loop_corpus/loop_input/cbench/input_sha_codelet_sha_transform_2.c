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
    A = 0x67452301L;
    B = 0xEFCDAB89L;
    C = 0x98BADCFEL;
    D = 0x10325476L;
    E = 0xC3D2E1F0L;
    temp = 0L;

    for (int j = 0; j < 80; ++j) {
        W[j] = j * j + 1732584193L;
    }
}