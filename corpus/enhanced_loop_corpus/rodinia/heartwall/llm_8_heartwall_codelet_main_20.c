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

extern int i;
extern public_struct public;
extern private_struct private[51];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and augmented trip count
    int limit = (public.endoPoints + 1) * 2;  // Increase effective trip count slightly
    for (i = 0; i < limit; i += 2) {
        int idx1 = i / 2;
        int idx2 = (i / 2) + 1;

        if (idx1 < public.endoPoints) {
            private[idx1].point_no = idx1;
            private[idx1].in_pointer = private[idx1].point_no * public.in_mod_elem;
            private[idx1].d_Row = public.d_endoRow;
            private[idx1].d_Col = public.d_endoCol;
            private[idx1].d_tRowLoc = public.d_tEndoRowLoc;
            private[idx1].d_tColLoc = public.d_tEndoColLoc;
            private[idx1].d_T = public.d_endoT;

            // Additional dummy arithmetic to increase computational load
            private[idx1].in_pointer += (private[idx1].point_no % 3) * (public.frame_rows > 0 ? public.frame_rows / (public.frame_rows % 7 + 1) : 1);
        }

        if (idx2 < public.endoPoints) {
            private[idx2].point_no = idx2;
            private[idx2].in_pointer = private[idx2].point_no * public.in_mod_elem;
            private[idx2].d_Row = public.d_endoRow;
            private[idx2].d_Col = public.d_endoCol;
            private[idx2].d_tRowLoc = public.d_tEndoRowLoc;
            private[idx2].d_tColLoc = public.d_tEndoColLoc;
            private[idx2].d_T = public.d_endoT;

            // Additional dummy arithmetic
            private[idx2].in_pointer += (private[idx2].point_no % 3) * (public.frame_cols > 0 ? public.frame_cols / (public.frame_cols % 5 + 1) : 1);
        }
    }
}
