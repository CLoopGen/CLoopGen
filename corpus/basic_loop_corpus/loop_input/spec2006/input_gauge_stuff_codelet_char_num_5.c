#include <stdint.h>

int length = 1000000;
int j;
int bdig[6] = {0};
int old = 0;

void init_vars() {
    length = 6;
    bdig[0] = 1;
    bdig[1] = 2;
    bdig[2] = 3;
    bdig[3] = 4;
    bdig[4] = 5;
    bdig[5] = 6;
    old = 0;
    j = 0;
}