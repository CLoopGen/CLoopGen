#include <stdint.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

AVInteger a;
AVInteger b;
int i;
int carry;

void init_vars() {
    a.v[0] = 1;
    a.v[1] = 2;
    a.v[2] = 3;
    a.v[3] = 4;
    a.v[4] = 5;
    a.v[5] = 6;
    a.v[6] = 7;
    a.v[7] = 8;

    b.v[0] = 8;
    b.v[1] = 7;
    b.v[2] = 6;
    b.v[3] = 5;
    b.v[4] = 4;
    b.v[5] = 3;
    b.v[6] = 2;
    b.v[7] = 1;

    i = 0;
    carry = 0;
}