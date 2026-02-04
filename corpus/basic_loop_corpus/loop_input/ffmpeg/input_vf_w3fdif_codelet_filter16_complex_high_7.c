#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
int16_t *coef;
int linesize;
uint16_t *in_lines_cur[5];
uint16_t *in_lines_adj[5];
int i;

static uint16_t in_lines_cur_data[5][65536];
static uint16_t in_lines_adj_data[5][65536];
static int32_t work_line_data[65536];
static int16_t coef_data[5];

void init_vars() {
    linesize = 65536;

    for (int j = 0; j < 5; j++) {
        in_lines_cur[j] = in_lines_cur_data[j];
        in_lines_adj[j] = in_lines_adj_data[j];
        for (int k = 0; k < linesize; k++) {
            in_lines_cur_data[j][k] = (uint16_t)(k + j);
            in_lines_adj_data[j][k] = (uint16_t)(k + j + 1);
        }
    }

    for (int j = 0; j < linesize; j++) {
        work_line_data[j] = (int32_t)j;
    }
    work_line = work_line_data;

    for (int j = 0; j < 5; j++) {
        coef_data[j] = (int16_t)(j + 1);
    }
    coef = coef_data;
}