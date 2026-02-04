#include <inttypes.h>
#include <stdint.h>

int x[40][2];
int i;
int64_t accu_re;

void init_vars() {
    accu_re = 0;
    for (int row = 0; row < 40; row++) {
        for (int col = 0; col < 2; col++) {
            x[row][col] = (row + 1) * 100 + col;
        }
    }
}