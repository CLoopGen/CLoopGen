#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t in_layout = 0x7FFFFFFF;
uint64_t out_layout = 0x7FFFFFFF;
int i;

double matrix[64][64];

void init_vars() {
    for (int row = 0; row < 64; ++row) {
        for (int col = 0; col < 64; ++col) {
            matrix[row][col] = 0.0;
        }
    }
    in_layout = 0x7FFFFFFF;
    out_layout = 0x7FFFFFFF;
}