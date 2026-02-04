#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst_color;
extern  uint8_t *src;
extern int src_linesize;
extern int src_linestep;
extern int int_x;
extern int int_y;
extern int frac_x;
extern int frac_y;
extern int i;
extern int int_x1;
extern int int_y1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_x = src_linestep * int_x;
    int base_x1 = src_linestep * int_x1;
    int base_y = src_linesize * int_y;
    int base_y1 = src_linesize * int_y1;
    int fx = frac_x;
    int fy = frac_y;
    int inv_fx = (1 << 16) - fx;
    int inv_fy = (1 << 16) - fy;
    for (i = 0; i < src_linestep; i++) {
        int idx00 = base_x + i + base_y;
        int idx01 = base_x1 + i + base_y;
        int idx10 = base_x + i + base_y1;
        int idx11 = base_x1 + i + base_y1;
        int s00 = src[idx00];
        int s01 = src[idx01];
        int s10 = src[idx10];
        int s11 = src[idx11];
        int s0 = (inv_fx * s00 + fx * s01) >> 16;
        int s1 = (inv_fx * s10 + fx * s11) >> 16;
        int result = (inv_fy * s0 + fy * s1) >> 16;
        dst_color[i] = result;
    }
}
