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
    float *d_in2_sub = private.d_in2_sub;
    float *d_in2_sub2_sqr = private.d_in2_sub2_sqr;
    float *d_conv = private.d_conv;
    int rows = public.in2_sub_rows;
    int rowlow1 = public.in2_sub_cumh_sel_rowlow - 1;
    int collow1 = public.in2_sub_cumh_sel_collow - 1;
    int rowlow2 = public.in2_sub_cumh_sel2_rowlow - 1;
    int collow2 = public.in2_sub_cumh_sel2_collow - 1;
    int mod_elem = public.in_mod_elem;
    float final_sum = in_final_sum;
    int sqr_rows = public.in2_sub2_sqr_rows;
    float accum_diff_sq = 0.0f;
    float conv_update = 0.0f;

    for (col = 0; col < public.in2_sub2_sqr_cols; col++) {
        int base_col1 = (col + collow1) * rows;
        int base_col2 = (col + collow2) * rows;
        int out_col = col * sqr_rows;
        // Introduce loop-carried dependency: accumulate sum of squares across rows
        accum_diff_sq = 0.0f;
        for (row = 0; row < sqr_rows; row++) {
            int idx1 = base_col1 + (row + rowlow1);
            int idx2 = base_col2 + (row + rowlow2);
            float temp = d_in2_sub[idx1];
            float temp2 = d_in2_sub[idx2];
            temp2 = temp - temp2;
            float diff_sq = temp2 * temp2;
            accum_diff_sq += diff_sq;  // WAW and RAW dependency introduced
            d_in2_sub2_sqr[out_col + row] = diff_sq;
        }
        // Use accumulated value to modify d_conv with column-level dependency
        conv_update = accum_diff_sq * final_sum / mod_elem;
        for (row = 0; row < sqr_rows; row++) {
            d_conv[out_col + row] -= conv_update;  // Uniform update based on column aggregate
        }
    }
}
