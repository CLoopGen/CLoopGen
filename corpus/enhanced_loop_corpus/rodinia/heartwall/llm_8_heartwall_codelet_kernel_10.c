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
extern float temp;
extern float temp2;
extern float in_final_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding redundant arithmetic operations.
    // Also reduces loop trip count by processing 2 iterations at a time, increasing arithmetic per iteration.

    int row_end = public.in2_sub2_sqr_rows - (public.in2_sub2_sqr_rows % 2);
    int col_end = public.in2_sub2_sqr_cols - (public.in2_sub2_sqr_cols % 2);

    for (col = 0; col < col_end; col += 2) {
        for (row = 0; row < row_end; row += 2) {
            // Process 2x2 block to simulate loop unrolling
            for (int dc = 0; dc < 2; dc++) {
                for (int dr = 0; dr < 2; dr++) {
                    int curr_row = row + dr;
                    int curr_col = col + dc;
                    ori_row = curr_row + public.in2_sub_cumh_sel_rowlow - 1;
                    ori_col = curr_col + public.in2_sub_cumh_sel_collow - 1;
                    temp = private.d_in2_sub[ori_col * public.in2_sub_rows + ori_row];
                    ori_row = curr_row + public.in2_sub_cumh_sel2_rowlow - 1;
                    ori_col = curr_col + public.in2_sub_cumh_sel2_collow - 1;
                    temp2 = private.d_in2_sub[ori_col * public.in2_sub_rows + ori_row];
                    temp2 = temp - temp2;

                    // Additional floating-point operations to increase computational load
                    float diff_sq = temp2 * temp2;
                    float scale_factor = 1.0f + (diff_sq * 0.0001f); // Artificial dependency
                    diff_sq *= scale_factor;

                    private.d_in2_sub2_sqr[curr_col * public.in2_sub2_sqr_rows + curr_row] = diff_sq;
                    private.d_conv[curr_col * public.in2_sub2_sqr_rows + curr_row] -= temp2 * in_final_sum / public.in_mod_elem;
                }
            }
        }
    }

    // Handle remaining rows
    for (; col < public.in2_sub2_sqr_cols; col++) {
        for (row = 0; row < public.in2_sub2_sqr_rows; row++) {
            ori_row = row + public.in2_sub_cumh_sel_rowlow - 1;
            ori_col = col + public.in2_sub_cumh_sel_collow - 1;
            temp = private.d_in2_sub[ori_col * public.in2_sub_rows + ori_row];
            ori_row = row + public.in2_sub_cumh_sel2_rowlow - 1;
            ori_col = col + public.in2_sub_cumh_sel2_collow - 1;
            temp2 = private.d_in2_sub[ori_col * public.in2_sub_rows + ori_row];
            temp2 = temp - temp2;
            private.d_in2_sub2_sqr[col * public.in2_sub2_sqr_rows + row] = temp2 * temp2;
            private.d_conv[col * public.in2_sub2_sqr_rows + row] = private.d_conv[col * public.in2_sub2_sqr_rows + row] - temp2 * in_final_sum / public.in_mod_elem;
        }
    }
}
