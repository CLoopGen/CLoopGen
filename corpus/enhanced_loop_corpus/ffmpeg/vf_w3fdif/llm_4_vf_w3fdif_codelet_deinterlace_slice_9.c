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



void loop(){
for (j = 0; j < n_coef_hf[filter]; j++) {
    y_in = (y_out + 1) + (j * 2) - n_coef_hf[filter];
    if (y_in < 0)
        y_in = (y_in % 2) + 2;
    if (y_in >= height) {
        y_in = height - 1 - ((y_in - height + 1) % (height + 1));
        if (y_in >= height || y_in < 0)
            y_in = 0;
    }
    in_lines_cur[j] = cur_data + (y_in * cur_line_stride);
    in_lines_adj[j] = adj_data + (y_in * adj_line_stride);
}
}
