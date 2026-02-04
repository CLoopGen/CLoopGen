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
extern float *d_in;
extern int row;
extern int col;
extern int ori_row;
extern int ori_col;
extern int ori_pointer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = public.in_mod_rows * public.in_mod_cols;
    int stride = 4;
    int i;

    for (i = 0; i < total_elements; i += stride) {
        int base_idx = i;
        int row0 = base_idx % public.in_mod_rows;
        int col0 = base_idx / public.in_mod_rows;

        if (col0 >= public.in_mod_cols) continue;

        ori_row = private.d_Row[private.point_no] - 25 + row0 - 1;
        ori_col = private.d_Col[private.point_no] - 25 + col0 - 1;
        ori_pointer = ori_col * public.frame_rows + ori_row;
        float alpha_val = public.alpha;
        float one_minus_alpha = 1.0f - alpha_val;
        d_in[base_idx] = alpha_val * d_in[base_idx] + one_minus_alpha * public.d_frame[ori_pointer];

        if (base_idx + 1 < total_elements && (base_idx + 1) / public.in_mod_rows == col0) {
            int row1 = (base_idx + 1) % public.in_mod_rows;
            int ori_ptr1 = (private.d_Col[private.point_no] - 25 + col0 - 1) * public.frame_rows + 
                           (private.d_Row[private.point_no] - 25 + row1 - 1);
            d_in[base_idx + 1] = alpha_val * d_in[base_idx + 1] + one_minus_alpha * public.d_frame[ori_ptr1];
        }

        if (base_idx + 2 < total_elements && (base_idx + 2) / public.in_mod_rows == col0) {
            int row2 = (base_idx + 2) % public.in_mod_rows;
            int ori_ptr2 = (private.d_Col[private.point_no] - 25 + col0 - 1) * public.frame_rows + 
                           (private.d_Row[private.point_no] - 25 + row2 - 1);
            d_in[base_idx + 2] = alpha_val * d_in[base_idx + 2] + one_minus_alpha * public.d_frame[ori_ptr2];
        }

        if (base_idx + 3 < total_elements && (base_idx + 3) / public.in_mod_rows == col0) {
            int row3 = (base_idx + 3) % public.in_mod_rows;
            int ori_ptr3 = (private.d_Col[private.point_no] - 25 + col0 - 1) * public.frame_rows + 
                           (private.d_Row[private.point_no] - 25 + row3 - 1);
            d_in[base_idx + 3] = alpha_val * d_in[base_idx + 3] + one_minus_alpha * public.d_frame[ori_ptr3];
        }
    }

    for (; i < total_elements; i++) {
        int row = i % public.in_mod_rows;
        int col = i / public.in_mod_rows;
        ori_row = private.d_Row[private.point_no] - 25 + row - 1;
        ori_col = private.d_Col[private.point_no] - 25 + col - 1;
        ori_pointer = ori_col * public.frame_rows + ori_row;
        d_in[i] = public.alpha * d_in[i] + (1.0f - public.alpha) * public.d_frame[ori_pointer];
    }
}
