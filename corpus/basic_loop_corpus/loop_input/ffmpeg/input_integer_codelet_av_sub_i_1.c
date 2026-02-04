#include <stdint.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

AVInteger a;
AVInteger b;
int i;
int carry;

void init_vars() {
    a.v[0] = 0x1234;
    a.v[1] = 0x5678;
    a.v[2] = 0x9ABC;
    a.v[3] = 0xDEF0;
    a.v[4] = 0x2468;
    a.v[5] = 0x1357;
    a.v[6] = 0x8ACE;
    a.v[7] = 0xFDBA;

    b.v[0] = 0x0123;
    b.v[1] = 0x4567;
    b.v[2] = 0x89AB;
    b.v[3] = 0xCDEF;
    b.v[4] = 0x1111;
    b.v[5] = 0x2222;
    b.v[6] = 0x3333;
    b.v[7] = 0x4444;

    i = 0;
    carry = 0x10000;
}