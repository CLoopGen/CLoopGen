#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int ss_h;
int ss_v;
int row_and_7;
int w;
int h;
int col_end;
unsigned int wide_filter_row_mask[2];
int t;
int m_col;
int y;
int m_row_8;
int m_row_4;

void init_vars() {
    ss_h = 1;
    ss_v = 1;
    row_and_7 = 0;
    w = 32;
    h = 16;
    col_end = 15;
    wide_filter_row_mask[0] = 0xFFFFFFFF;
    wide_filter_row_mask[1] = 0xAAAAAAAA;
    t = 1;
    m_col = 0xFF;
    m_row_8 = 0x80;
    m_row_4 = 0x40;

    size_t total_size = 256 * 1024 * 1024; // Target ~256MB
    size_t num_rows = total_size / (8 * 4 * sizeof(uint8_t));
    if (num_rows < (size_t)(h + row_and_7)) {
        num_rows = h + row_and_7;
    }

    mask = aligned_alloc(32, num_rows * sizeof(*mask));
    for (size_t i = 0; i < num_rows; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                mask[i][j][k] = 0;
            }
        }
    }
}