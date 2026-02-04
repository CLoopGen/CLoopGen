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
    int8_t coef = n_coef_lf[filter];
    for (j = 0; j < coef; j++) {
        y_in = (y_out + 1) + (j * 2) - coef;
        y_in = (y_in < 0) ? (y_in % 2 ? 1 : 0) : y_in; // Partial elimination of while using conditional
        y_in = (y_in >= height) ? height - ((y_in - height) % 2) - 1 : y_in;
        in_lines_cur[j] = cur_data + (y_in * cur_line_stride);
    }
}
