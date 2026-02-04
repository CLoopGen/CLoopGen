#include <inttypes.h>

int squaresize[4];
int nsquares[4];
int j;
int dir;

void init_vars() {
    j = 1;
    squaresize[0] = 0;
    squaresize[1] = 1;
    squaresize[2] = 2;
    squaresize[3] = 3;
    nsquares[0] = 0;
    nsquares[1] = 2;
    nsquares[2] = 0;
    nsquares[3] = 0;
}