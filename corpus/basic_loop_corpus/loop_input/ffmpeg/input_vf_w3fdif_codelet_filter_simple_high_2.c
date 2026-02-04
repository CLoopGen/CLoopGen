#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
uint8_t *in_lines_cur[3];
uint8_t *in_lines_adj[3];
int16_t *coef;
int linesize;
int i;

static uint8_t *in_buffer_cur[3];
static uint8_t *in_buffer_adj[3];
static int32_t *work_buffer;
static int16_t coef_data[3];

void init_vars() {
    linesize = 16 << 20; // 16 million elements, roughly 64MB input per buffer

    work_buffer = (int32_t*)calloc(linesize + 64, sizeof(int32_t));
    if (!work_buffer) exit(1);

    for (int j = 0; j < 3; j++) {
        in_buffer_cur[j] = (uint8_t*)malloc(linesize + 64);
        in_buffer_adj[j] = (uint8_t*)malloc(linesize + 64);
        if (!in_buffer_cur[j] || !in_buffer_adj[j]) exit(1);

        in_lines_cur[j] = in_buffer_cur[j];
        in_lines_adj[j] = in_buffer_adj[j];
    }

    coef = coef_data;
    coef[0] = 1;
    coef[1] = 2;
    coef[2] = 3;

    work_line = work_buffer;
}