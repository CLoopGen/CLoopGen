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
int **weight_ptr[2 + 5]; // assuming max list_offset is 5
int **offset_ptr[2 + 5];
int w_idx[2 + 5], o_idx[2 + 5];

for (clist = 0; clist < 2 + list_offset; clist++) {
    weight_ptr[clist] = wp_weight[clist];
    offset_ptr[clist] = wp_offset[clist];
    w_idx[clist] = listXsize[clist];
    o_idx[clist] = listXsize[clist];
}

for (clist = 0; clist < 2 + list_offset; clist++) {
    int limit = w_idx[clist];
    int **w_base = weight_ptr[clist];
    int **o_base = offset_ptr[clist];
    int luma_val = 1 << luma_log_weight_denom;
    int chroma_val = 1 << chroma_log_weight_denom;
    for (index = 0; index < limit; index++) {
        int *w_row = w_base[index];
        int *o_row = o_base[index];
        w_row[0] = luma_val;
        w_row[1] = chroma_val;
        w_row[2] = chroma_val;
        o_row[0] = 0;
        o_row[1] = 0;
        o_row[2] = 0;
    }
}
}
