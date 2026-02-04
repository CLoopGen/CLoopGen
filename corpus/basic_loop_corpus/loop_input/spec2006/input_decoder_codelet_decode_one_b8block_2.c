#include <inttypes.h>

int bx;
int by;
int mv[2][4][4];
int bx0;
int bx1;
int by0;
int by1;

void init_vars() {
    bx0 = 0;
    bx1 = 4;
    by0 = 0;
    by1 = 4;
}