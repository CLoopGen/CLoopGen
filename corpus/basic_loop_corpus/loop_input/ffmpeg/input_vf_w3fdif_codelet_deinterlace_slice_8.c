#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int8_t n_coef_lf[2] = {4, 6};
int filter = 0;
uint8_t *in_lines_cur[5];
uint8_t *cur_data;
int height = 1080;
int cur_line_stride = 1920;
int j;
int y_in;
int y_out;

void init_vars() {
    y_out = 540;

    if (cur_data == NULL) {
        size_t total_size = (size_t)height * cur_line_stride;
        cur_data = (uint8_t*)aligned_alloc(32, total_size);
        if (!cur_data) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
        memset(cur_data, 0x7F, total_size);
    }

    for (int i = 0; i < 5; i++) {
        in_lines_cur[i] = NULL;
    }
}