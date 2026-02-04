#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *work_line;
uint8_t *in_lines_cur[4];
int16_t *coef;
int linesize;
int i;

int32_t *work_line_base;
uint8_t *in_lines_base[4];

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // For typical modern CPU, assume simple arithmetic and memory ops
    // Aim for moderate cache pressure: ~64MB total input
    linesize = 16777216;  // 16M elements (adjustable)

    // Allocate work_line buffer
    work_line_base = aligned_alloc(32, linesize * sizeof(int32_t));
    work_line = work_line_base;

    // Allocate coefficient array
    static int16_t coef_data[4] = { 1, 2, 3, 4 };
    coef = coef_data;

    // Allocate 4 input line buffers
    for (int j = 0; j < 4; j++) {
        in_lines_base[j] = aligned_alloc(32, linesize * sizeof(uint8_t));
        in_lines_cur[j] = in_lines_base[j];
        // Initialize with non-zero values for meaningful computation
        for (int k = 0; k < linesize; k++) {
            in_lines_base[j][k] = (uint8_t)(k % 255 + 1);
        }
    }

    // Ensure work_line is initialized to avoid undefined behavior
    for (int j = 0; j < linesize; j++) {
        work_line_base[j] = 0;
    }
}