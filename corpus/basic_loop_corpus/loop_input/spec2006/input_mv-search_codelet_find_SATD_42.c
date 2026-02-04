#include <stdint.h>
#include <string.h>

int curr_diff[16][16];
int i;
int j;
int k;
int x;
int y;
int block_size_x;
int block_size_y;
int block_size;
int diff[256];

void init_vars() {
    // Initialize the 16x16 curr_diff array with non-zero values for meaningful data transfer
    for (int row = 0; row < 16; ++row) {
        for (int col = 0; col < 16; ++col) {
            curr_diff[row][col] = (row * 16 + col) & 0xFF;
        }
    }

    // Set block dimensions to ensure we stay within bounds and create measurable workload
    block_size_x = 16;
    block_size_y = 16;
    block_size = 4;  // Tiling factor

    // Initialize loop indices
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    k = 0;

    // Zero-initialize diff array
    memset(diff, 0, sizeof(diff));
}