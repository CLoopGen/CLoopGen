#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
uint8_t *in_lines_cur[5];
uint8_t *in_lines_adj[5];
int16_t *coef;
int linesize;
int i;

static uint8_t *in_buffer;
static uint8_t *adj_buffer;
static int32_t *work_buffer;

void init_vars() {
    // Set data size to target ~0.01s runtime - use ~32-64M coefficients for reasonable speed
    linesize = 16000000;  // 16M elements

    // Allocate coefficient array
    coef = (int16_t*)aligned_alloc(32, 5 * sizeof(int16_t));
    for (int c = 0; c < 5; c++) {
        coef[c] = (int16_t)(c + 1);  // arbitrary non-zero values
    }

    // Total input buffer size: 5 lines * linesize bytes each
    in_buffer = (uint8_t*)aligned_alloc(32, 5 * linesize * sizeof(uint8_t));
    adj_buffer = (uint8_t*)aligned_alloc(32, 5 * linesize * sizeof(uint8_t));
    work_buffer = (int32_t*)aligned_alloc(32, linesize * sizeof(int32_t));

    // Initialize pointers to start of each line
    for (int idx = 0; idx < 5; idx++) {
        in_lines_cur[idx] = &in_buffer[idx * linesize];
        in_lines_adj[idx] = &adj_buffer[idx * linesize];
    }

    // Initialize work_line to start of work buffer
    work_line = work_buffer;

    // Initialize all input and work memory to avoid undefined behavior
    for (int j = 0; j < 5 * linesize; j++) {
        in_buffer[j] = j & 0xFF;
        adj_buffer[j] = (j + 42) & 0xFF;
    }
    for (int j = 0; j < linesize; j++) {
        work_buffer[j] = 0;
    }
}