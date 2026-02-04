#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int m_col;
int mask_id;
int step1d;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16MB working set
    const size_t num_rows = total_data_size / (8 * 4);
    mask = aligned_alloc(32, num_rows * sizeof(*mask));
    for (size_t i = 0; i < num_rows; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 4; ++k) {
                mask[i][j][k] = 0;
            }
        }
    }

    row_and_7 = 0;
    h = 8;
    step1d = 1;
    mask_id = 0;
    m_col = 1;
}

void loop(); 

__attribute__((constructor))
static void constructor() {
    init_vars();
}