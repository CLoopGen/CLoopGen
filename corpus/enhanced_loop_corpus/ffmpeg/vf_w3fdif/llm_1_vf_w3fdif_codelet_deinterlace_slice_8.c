#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t n_coef_lf[2];
extern  int filter;
extern uint8_t *in_lines_cur[5];
extern uint8_t *cur_data;
extern  int height;
extern  int cur_line_stride;
extern int j;
extern int y_in;
extern int y_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = n_coef_lf[filter];
    int temp_y_in;
    for (j = 0; j < limit; j++) {
        temp_y_in = (y_out + 1) + (j * 2) - limit;
        temp_y_in = temp_y_in & 1 ? (temp_y_in < 0 ? 1 : (temp_y_in % 2)) : (temp_y_in % 2);
        if (temp_y_in < 0) temp_y_in += 2;
        y_in = temp_y_in >= height ? 2 * (height - 1) - (temp_y_in % height) : temp_y_in;
        if (y_in >= height) y_in = height - 1;
        if (y_in < 0) y_in = 0;
        in_lines_cur[j] = cur_data + (y_in * cur_line_stride);
    }
}
