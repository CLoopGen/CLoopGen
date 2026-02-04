#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t n_coef_hf[2] = {4, 4};
int filter = 0;
uint8_t *in_lines_cur[5];
uint8_t *in_lines_adj[5];
uint8_t *cur_data;
uint8_t *adj_data;
int height = 1080;
int cur_line_stride = 1920;
int adj_line_stride = 1920;
int j;
int y_in;
int y_out = 540;

void init_vars() {
    const size_t total_size = (size_t)height * cur_line_stride;
    cur_data = (uint8_t*)aligned_alloc(32, total_size);
    adj_data = (uint8_t*)aligned_alloc(32, total_size);

    for (int i = 0; i < 5; i++) {
        in_lines_cur[i] = NULL;
        in_lines_adj[i] = NULL;
    }

    if (!cur_data || !adj_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        cur_data[i] = rand() % 256;
        adj_data[i] = rand() % 256;
    }
}