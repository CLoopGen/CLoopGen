#include <stdint.h>
#include <string.h>

int n = 140;
int path[2800][2800];
int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < 2800; ++ii) {
        for (int jj = 0; jj < 2800; ++jj) {
            path[ii][jj] = (ii == jj) ? 0 : (300 + (ii * jj) % 100);
        }
    }
    i = 0;
    j = 0;
    k = 0;
}