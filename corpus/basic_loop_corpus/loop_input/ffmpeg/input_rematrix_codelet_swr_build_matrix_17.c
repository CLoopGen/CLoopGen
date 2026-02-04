#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double matrix[18][18];
int64_t in_ch_layout = 0x1FFFF;  // Supports up to 17 bits for 18x18 matrix
int64_t out_ch_layout = 0x1FFFF;

void init_vars() {
    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 18; ++col) {
            matrix[row][col] = 0.0;
        }
    }
    in_ch_layout = 0x1FFFF;  
    out_ch_layout = 0x1FFFF;  
}