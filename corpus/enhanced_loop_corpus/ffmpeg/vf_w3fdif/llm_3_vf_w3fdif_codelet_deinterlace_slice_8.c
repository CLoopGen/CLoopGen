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
    uint8_t **in_cur = in_lines_cur;
    int offset = (y_out + 1) - coef;
    for (j = 0; j < coef; j++) {
        int index = offset + (j << 1);
        int clamped_y = index >= 0 ? (index < height ? index : height - 1 - (index - height + 1) % (height - 1)) 
                                   : (-index) % 2;
        in_cur[j] = cur_data + (clamped_y * cur_line_stride);
    }
}
