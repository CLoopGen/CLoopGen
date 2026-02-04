#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t n_coef_hf[2];
extern  int filter;
extern uint8_t *in_lines_cur[5];
extern uint8_t *in_lines_adj[5];
extern uint8_t *cur_data;
extern uint8_t *adj_data;
extern  int height;
extern  int cur_line_stride;
extern  int adj_line_stride;
extern int j;
extern int y_in;
extern int y_out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int8_t coef = n_coef_hf[filter];
    int temp_offsets_cur[5], temp_offsets_adj[5];
    for (j = 0; j < coef; j++) {
        int y_temp = (y_out + 1) + (j * 2) - coef;
        y_temp = y_temp < 0 ? -y_temp : y_temp;
        y_temp = y_temp >= height ? 2 * height - y_temp - 2 : y_temp;
        while (y_temp < 0) y_temp += 2;
        while (y_temp >= height) y_temp -= 2;
        temp_offsets_cur[j] = y_temp * cur_line_stride;
        temp_offsets_adj[j] = y_temp * adj_line_stride;
    }
    for (j = 0; j < coef; j++) {
        in_lines_cur[j] = cur_data + temp_offsets_cur[j];
        in_lines_adj[j] = adj_data + temp_offsets_adj[j];
    }
}
