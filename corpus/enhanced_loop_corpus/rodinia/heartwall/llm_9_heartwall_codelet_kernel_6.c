#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct public_struct {
    int tSize;
    int sSize;
    int maxMove;
    float alpha;
    int endoPoints;
    int d_endo_mem;
    int *d_endoRow;
    int *d_endoCol;
    int *d_tEndoRowLoc;
    int *d_tEndoColLoc;
    float *d_endoT;
    int epiPoints;
    int d_epi_mem;
    int *d_epiRow;
    int *d_epiCol;
    int *d_tEpiRowLoc;
    int *d_tEpiColLoc;
    float *d_epiT;
    int allPoints;
    int *d_frames;
    int frames;
    int frame_no;
    float *d_frame;
    int frame_rows;
    int frame_cols;
    int frame_elem;
    int frame_mem;
    int in2_rows;
    int in2_cols;
    int in2_elem;
    int in2_mem;
    int in_mod_rows;
    int in_mod_cols;
    int in_mod_elem;
    int in_mod_mem;
    int ioffset;
    int joffset;
    int conv_rows;
    int conv_cols;
    int conv_elem;
    int conv_mem;
    int in2_pad_add_rows;
    int in2_pad_add_cols;
    int in2_pad_rows;
    int in2_pad_cols;
    int in2_pad_elem;
    int in2_pad_mem;
    int in2_pad_cumv_sel_rowlow;
    int in2_pad_cumv_sel_rowhig;
    int in2_pad_cumv_sel_collow;
    int in2_pad_cumv_sel_colhig;
    int in2_pad_cumv_sel2_rowlow;
    int in2_pad_cumv_sel2_rowhig;
    int in2_pad_cumv_sel2_collow;
    int in2_pad_cumv_sel2_colhig;
    int in2_sub_rows;
    int in2_sub_cols;
    int in2_sub_elem;
    int in2_sub_mem;
    int in2_sub_cumh_sel_rowlow;
    int in2_sub_cumh_sel_rowhig;
    int in2_sub_cumh_sel_collow;
    int in2_sub_cumh_sel_colhig;
    int in2_sub_cumh_sel2_rowlow;
    int in2_sub_cumh_sel2_rowhig;
    int in2_sub_cumh_sel2_collow;
    int in2_sub_cumh_sel2_colhig;
    int in2_sub2_sqr_rows;
    int in2_sub2_sqr_cols;
    int in2_sub2_sqr_elem;
    int in2_sub2_sqr_mem;
    int tMask_rows;
    int tMask_cols;
    int tMask_elem;
    int tMask_mem;
    int mask_rows;
    int mask_cols;
    int mask_elem;
    int mask_mem;
    int mask_conv_rows;
    int mask_conv_cols;
    int mask_conv_elem;
    int mask_conv_mem;
    int mask_conv_ioffset;
    int mask_conv_joffset;
} public_struct;

typedef struct private_struct {
    int point_no;
    int in_pointer;
    int *d_Row;
    int *d_Col;
    int *d_tRowLoc;
    int *d_tColLoc;
    float *d_T;
    float *d_in2;
    float *d_in2_sqr;
    float *d_in_mod;
    float *d_in_sqr;
    float *d_conv;
    float *d_in2_pad;
    float *d_in2_sub;
    float *d_in2_sub2_sqr;
    float *d_tMask;
    float *d_mask_conv;
    float *in_partial_sum;
    float *in_sqr_partial_sum;
    float *par_max_val;
    int *par_max_coo;
} private_struct;

extern public_struct public;
extern private_struct private;
extern int row;
extern int col;
extern int ori_row;
extern int ori_col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase computational intensity by unrolling inner loop by factor of 2
// and increasing arithmetic operations per iteration

int start_row = public.in2_pad_add_rows;
int end_row = public.in2_pad_add_rows + public.in2_rows;
int start_col = public.in2_pad_add_cols;
int end_col = public.in2_pad_add_cols + public.in2_cols;

for (col = 0; col < public.in2_pad_cols; col++) {
    int col_offset = col * public.in2_pad_rows;
    for (row = 0; row < public.in2_pad_rows - 1; row += 2) {
        int idx1 = col_offset + row;
        int idx2 = col_offset + row + 1;

        // First element
        private.d_in2_pad[idx1] = 0;
        if (row >= start_row && row < end_row && col >= start_col && col < end_col) {
            ori_row = row - public.in2_pad_add_rows;
            ori_col = col - public.in2_pad_add_cols;
            private.d_in2_pad[idx1] = private.d_in2[ori_col * public.in2_rows + ori_row];
        }

        // Second element
        private.d_in2_pad[idx2] = 0;
        if (row + 1 >= start_row && row + 1 < end_row && col >= start_col && col < end_col) {
            ori_row = (row + 1) - public.in2_pad_add_rows;
            ori_col = col - public.in2_pad_add_cols;
            private.d_in2_pad[idx2] = private.d_in2[ori_col * public.in2_rows + ori_row];
        }
    }
    // Handle odd-sized rows
    if (row == public.in2_pad_rows - 1) {
        int idx = col * public.in2_pad_rows + row;
        private.d_in2_pad[idx] = 0;
        if (row >= start_row && row < end_row && col >= start_col && col < end_col) {
            ori_row = row - public.in2_pad_add_rows;
            ori_col = col - public.in2_pad_add_cols;
            private.d_in2_pad[idx] = private.d_in2[ori_col * public.in2_rows + ori_row];
        }
    }
}
}
