#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int b;
FLOAT8 en[3];
FLOAT8 mx;

void init_vars() {
    b = 0;
    en[0] = 1.5;
    en[1] = 3.2;
    en[2] = 2.8;
    mx = 0.0;
}