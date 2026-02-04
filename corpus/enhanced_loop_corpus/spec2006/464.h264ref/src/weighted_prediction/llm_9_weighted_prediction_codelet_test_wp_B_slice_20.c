#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int luma_log_weight_denom;
extern int chroma_log_weight_denom;
extern int listXsize[6];
extern int _usr_index;
extern int list_offset;
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
int total_iters = 0;
for (int temp_clist = 0; temp_clist < 2 + list_offset; temp_clist++) {
    total_iters += listXsize[temp_clist];
}
int unroll_factor = 3;
int remainder = total_iters % unroll_factor;
int main_loop_count = total_iters - remainder;

int iter = 0;
for (clist = 0; clist < 2 + list_offset && iter < main_loop_count; clist++) {
    for (; index < listXsize[clist] && iter < main_loop_count; index++) {
        wp_weight[clist][index][0] = 1 << luma_log_weight_denom;
        wp_weight[clist][index][1] = 1 << chroma_log_weight_denom;
        wp_weight[clist][index][2] = 1 << chroma_log_weight_denom;
        wp_offset[clist][index][0] = 0;
        wp_offset[clist][index][1] = 0;
        wp_offset[clist][index][2] = 0;
        iter++;
    }
    if (index >= listXsize[clist]) {
        index = 0;
    }
}
while (iter < total_iters) {
    wp_weight[clist][index][0] = 1 << luma_log_weight_denom;
    wp_weight[clist][index][1] = 1 << chroma_log_weight_denom;
    wp_weight[clist][index][2] = 1 << chroma_log_weight_denom;
    wp_offset[clist][index][0] = 0;
    wp_offset[clist][index][1] = 0;
    wp_offset[clist][index][2] = 0;
    index++;
    if (index >= listXsize[clist]) {
        index = 0;
        clist++;
    }
    iter++;
}
}
