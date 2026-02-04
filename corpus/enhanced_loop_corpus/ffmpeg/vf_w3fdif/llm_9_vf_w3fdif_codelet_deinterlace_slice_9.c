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
    int trip_count = (n_coef_hf[filter] + 3) / 4 * 4; // Round up to nearest multiple of 4 for unrolling
    int coef = n_coef_hf[filter];
    j = 0;
    // Unrolled loop with reduced conditionals and increased arithmetic per iteration
    for (; j + 3 < trip_count; j += 4) {
        // Compute 4 iterations at once with manual loop unrolling
        int y_in0 = (y_out + 1) + (j * 2)     - coef;
        int y_in1 = (y_out + 1) + ((j+1) * 2) - coef;
        int y_in2 = (y_out + 1) + ((j+2) * 2) - coef;
        int y_in3 = (y_out + 1) + ((j+3) * 2) - coef;

        // Clamp using arithmetic folding without loops: reflect within [0, height)
        y_in0 = (y_in0 < 0) ? (-y_in0) % height : (y_in0 >= height) ? (2*(height-1) - y_in0) % height : y_in0;
        y_in1 = (y_in1 < 0) ? (-y_in1) % height : (y_in1 >= height) ? (2*(height-1) - y_in1) % height : y_in1;
        y_in2 = (y_in2 < 0) ? (-y_in2) % height : (y_in2 >= height) ? (2*(height-1) - y_in2) % height : y_in2;
        y_in3 = (y_in3 < 0) ? (-y_in3) % height : (y_in3 >= height) ? (2*(height-1) - y_in3) % height : y_in3;

        in_lines_cur[j]   = cur_data + (y_in0 * cur_line_stride);
        in_lines_adj[j]   = adj_data + (y_in0 * adj_line_stride);
        in_lines_cur[j+1] = cur_data + (y_in1 * cur_line_stride);
        in_lines_adj[j+1] = adj_data + (y_in1 * adj_line_stride);
        in_lines_cur[j+2] = cur_data + (y_in2 * cur_line_stride);
        in_lines_adj[j+2] = adj_data + (y_in2 * adj_line_stride);
        in_lines_cur[j+3] = cur_data + (y_in3 * cur_line_stride);
        in_lines_adj[j+3] = adj_data + (y_in3 * adj_line_stride);
    }
    // Handle remaining iterations
    for (; j < n_coef_hf[filter]; j++) {
        y_in = (y_out + 1) + (j * 2) - coef;
        y_in = (y_in < 0) ? (-y_in) % height : (y_in >= height) ? (2*(height-1) - y_in) % height : y_in;
        in_lines_cur[j] = cur_data + (y_in * cur_line_stride);
        in_lines_adj[j] = adj_data + (y_in * adj_line_stride);
    }
}
