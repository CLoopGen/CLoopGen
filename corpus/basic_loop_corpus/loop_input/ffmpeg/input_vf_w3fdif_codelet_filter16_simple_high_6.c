#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
int16_t *coef;
int linesize;
uint16_t *in_lines_cur[3];
uint16_t *in_lines_adj[3];
int i;

static uint16_t in_lines_cur_data[3][1 << 18];    // ~512KB per buffer
static uint16_t in_lines_adj_data[3][1 << 18];
static int32_t work_line_data[1 << 18];
static int16_t coef_data[3] = {1, 2, 3};

void init_vars() {
    linesize = 1 << 18;  // 262144 elements

    for (int j = 0; j < 3; j++) {
        in_lines_cur[j] = in_lines_cur_data[j];
        in_lines_adj[j] = in_lines_adj_data[j];
    }

    work_line = work_line_data;
    coef = coef_data;

    // Initialize input data to non-zero values to ensure meaningful computation
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < linesize; k++) {
            in_lines_cur_data[j][k] = (k + j) & 0xFFFF;
            in_lines_adj_data[j][k] = (k + j + 1) & 0xFFFF;
        }
    }

    for (int j = 0; j < linesize; j++) {
        work_line_data[j] = j & 0x7FFFFFFF;
    }
}