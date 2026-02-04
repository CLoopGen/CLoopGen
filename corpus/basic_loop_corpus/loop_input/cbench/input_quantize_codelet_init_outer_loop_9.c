#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int b;
FLOAT8 en[3];
FLOAT8 mx;

void init_vars() {
    en[0] = 1.0e-10;
    en[1] = 5.0e-14;
    en[2] = 2.0e-12;
    mx = 1.0e-11;
    b = 0;
}