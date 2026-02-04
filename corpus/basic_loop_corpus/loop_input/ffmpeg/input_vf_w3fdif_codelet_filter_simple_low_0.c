#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
uint8_t *in_lines_cur[2];
int16_t *coef;
int linesize;
int i;

static uint8_t *in_buffer0;
static uint8_t *in_buffer1;
static int32_t *work_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    linesize = data_size;

    in_buffer0 = (uint8_t *)aligned_alloc(32, linesize * sizeof(uint8_t));
    in_buffer1 = (uint8_t *)aligned_alloc(32, linesize * sizeof(uint8_t));
    work_buffer = (int32_t *)aligned_alloc(32, linesize * sizeof(int32_t));

    if (!in_buffer0 || !in_buffer1 || !work_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < linesize; j++) {
        in_buffer0[j] = (uint8_t)(j & 0xFF);
        in_buffer1[j] = (uint8_t)((j + 50) & 0xFF);
        work_buffer[j] = 0;
    }

    coef = (int16_t *)malloc(2 * sizeof(int16_t));
    if (!coef) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    coef[0] = 300;
    coef[1] = -200;

    in_lines_cur[0] = in_buffer0;
    in_lines_cur[1] = in_buffer1;
    work_line = work_buffer;
}