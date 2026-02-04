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
extern int jp1;
extern int ja1;
extern int ja2;
extern int ip1;
extern int ia1;
extern int ia2;
extern int ja;
extern int jb;
extern int ia;
extern int ib;
extern float s;
extern int i;
extern int j;
extern int row;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect indexing via precomputed indices
    // Precompute valid (ja, ia) pairs to enable indirect memory access
    int max_pairs = (public.tMask_cols + public.tMask_rows) * (public.tMask_cols + public.tMask_rows); // Over-approximate
    int *indirect_ja = (int*)malloc(max_pairs * sizeof(int));
    int *indirect_ia = (int*)malloc(max_pairs * sizeof(int));
    int *indirect_idx = (int*)malloc(public.mask_conv_cols * public.mask_conv_rows * sizeof(int));

    // Precompute output indices
    for (col = 1; col <= public.mask_conv_cols; col++) {
        for (row = 1; row <= public.mask_conv_rows; row++) {
            int out_idx = (col - 1) * public.mask_conv_rows + (row - 1);
            indirect_idx[(col - 1) * public.mask_conv_rows + (row - 1)] = out_idx;
        }
    }

    for (col = 1; col <= public.mask_conv_cols; col++) {
        j = col + public.mask_conv_joffset;
        jp1 = j + 1;
        ja1 = (public.mask_cols < jp1) ? jp1 - public.mask_cols : 1;
        ja2 = (public.tMask_cols < j) ? public.tMask_cols : j;
        for (row = 1; row <= public.mask_conv_rows; row++) {
            i = row + public.mask_conv_ioffset;
            ip1 = i + 1;
            ia1 = (public.mask_rows < ip1) ? ip1 - public.mask_rows : 1;
            ia2 = (public.tMask_rows < i) ? public.tMask_rows : i;

            // Collect valid (ja, ia) pairs
            int pair_count = 0;
            for (ja = ja1; ja <= ja2; ja++) {
                for (ia = ia1; ia <= ia2; ia++) {
                    indirect_ja[pair_count] = ja;
                    indirect_ia[pair_count] = ia;
                    pair_count++;
                }
            }

            s = 0.0f;
            // Use indirect access through collected indices
            for (int p = 0; p < pair_count; p++) {
                int curr_ja = indirect_ja[p];
                int curr_ia = indirect_ia[p];
                int src_idx = public.tMask_rows * (curr_ja - 1) + curr_ia - 1;
                s += private.d_tMask[src_idx] * 1.0f;
            }

            int out_idx = indirect_idx[(col - 1) * public.mask_conv_rows + (row - 1)];
            private.d_mask_conv[out_idx] = private.d_conv[out_idx] * s;
        }
    }

    free(indirect_ja);
    free(indirect_ia);
    free(indirect_idx);
}
