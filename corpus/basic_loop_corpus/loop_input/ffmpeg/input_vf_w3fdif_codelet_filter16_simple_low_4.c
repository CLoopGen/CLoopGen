#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
int16_t *coef;
int linesize;
uint16_t *in_lines_cur[2];
int i;

static uint16_t *in_buffer0;
static uint16_t *in_buffer1;
static int32_t *work_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of input data
    linesize = data_size / sizeof(uint16_t);

    in_buffer0 = (uint16_t *)calloc(linesize, sizeof(uint16_t));
    in_buffer1 = (uint16_t *)calloc(linesize, sizeof(uint16_t));
    work_buffer = (int32_t *)calloc(linesize, sizeof(int32_t));
    coef = (int16_t *)malloc(2 * sizeof(int16_t));

    if (!in_buffer0 || !in_buffer1 || !work_buffer || !coef) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < linesize; j++) {
        in_buffer0[j] = (uint16_t)(j & 0xFFFF);
        in_buffer1[j] = (uint16_t)((j * 3) & 0xFFFF);
    }
    coef[0] = 32;
    coef[1] = 64;

    work_line = work_buffer;
    in_lines_cur[0] = in_buffer0;
    in_lines_cur[1] = in_buffer1;
}