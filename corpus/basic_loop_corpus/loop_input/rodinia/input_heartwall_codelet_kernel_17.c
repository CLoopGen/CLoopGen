#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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

public_struct public;
private_struct private;
int i;
float fin_max_val;
int fin_max_coo;

void init_vars() {
    // Set mask_conv_elem to achieve ~100ms runtime: assume 1e8 iterations at ~1ns per iteration
    // Adjust based on typical CPU speed; aim for about 100 million elements
    public.mask_conv_elem = 100000000 / sizeof(float);  // ~400MB array, adjust if needed
    public.mask_conv_mem = public.mask_conv_elem * sizeof(float);

    // Allocate memory for d_mask_conv
    private.d_mask_conv = (float*)calloc(public.mask_conv_elem, sizeof(float));
    if (!private.d_mask_conv) {
        exit(1);
    }

    // Initialize most of the array to small values
    for (int idx = 0; idx < public.mask_conv_elem - 1; idx++) {
        private.d_mask_conv[idx] = (float)(idx % 1000) / 1000.0f;
    }
    // Place a maximum near the end to ensure loop runs fully
    private.d_mask_conv[public.mask_conv_elem - 1] = 1.5f;

    // Initialize fin_max_val to a value lower than expected minimum
    fin_max_val = 0.0f;
    fin_max_coo = -1;

    // Initialize other fields to plausible values (mostly zeros)
    public.tSize = 0;
    public.sSize = 0;
    public.maxMove = 0;
    public.alpha = 0.0f;
    public.endoPoints = 0;
    public.d_endo_mem = 0;
    public.d_endoRow = NULL;
    public.d_endoCol = NULL;
    public.d_tEndoRowLoc = NULL;
    public.d_tEndoColLoc = NULL;
    public.d_endoT = NULL;
    public.epiPoints = 0;
    public.d_epi_mem = 0;
    public.d_epiRow = NULL;
    public.d_epiCol = NULL;
    public.d_tEpiRowLoc = NULL;
    public.d_tEpiColLoc = NULL;
    public.d_epiT = NULL;
    public.allPoints = 0;
    public.d_frames = NULL;
    public.frames = 0;
    public.frame_no = 0;
    public.d_frame = NULL;
    public.frame_rows = 0;
    public.frame_cols = 0;
    public.frame_elem = 0;
    public.frame_mem = 0;
    public.in2_rows = 0;
    public.in2_cols = 0;
    public.in2_elem = 0;
    public.in2_mem = 0;
    public.in_mod_rows = 0;
    public.in_mod_cols = 0;
    public.in_mod_elem = 0;
    public.in_mod_mem = 0;
    public.ioffset = 0;
    public.joffset = 0;
    public.conv_rows = 0;
    public.conv_cols = 0;
    public.conv_elem = 0;
    public.conv_mem = 0;
    public.in2_pad_add_rows = 0;
    public.in2_pad_add_cols = 0;
    public.in2_pad_rows = 0;
    public.in2_pad_cols = 0;
    public.in2_pad_elem = 0;
    public.in2_pad_mem = 0;
    public.in2_pad_cumv_sel_rowlow = 0;
    public.in2_pad_cumv_sel_rowhig = 0;
    public.in2_pad_cumv_sel_collow = 0;
    public.in2_pad_cumv_sel_colhig = 0;
    public.in2_pad_cumv_sel2_rowlow = 0;
    public.in2_pad_cumv_sel2_rowhig = 0;
    public.in2_pad_cumv_sel2_collow = 0;
    public.in2_pad_cumv_sel2_colhig = 0;
    public.in2_sub_rows = 0;
    public.in2_sub_cols = 0;
    public.in2_sub_elem = 0;
    public.in2_sub_mem = 0;
    public.in2_sub_cumh_sel_rowlow = 0;
    public.in2_sub_cumh_sel_rowhig = 0;
    public.in2_sub_cumh_sel_collow = 0;
    public.in2_sub_cumh_sel_colhig = 0;
    public.in2_sub_cumh_sel2_rowlow = 0;
    public.in2_sub_cumh_sel2_rowhig = 0;
    public.in2_sub_cumh_sel2_collow = 0;
    public.in2_sub_cumh_sel2_colhig = 0;
    public.in2_sub2_sqr_rows = 0;
    public.in2_sub2_sqr_cols = 0;
    public.in2_sub2_sqr_elem = 0;
    public.in2_sub2_sqr_mem = 0;
    public.tMask_rows = 0;
    public.tMask_cols = 0;
    public.tMask_elem = 0;
    public.tMask_mem = 0;
    public.mask_rows = 0;
    public.mask_cols = 0;
    public.mask_elem = 0;
    public.mask_mem = 0;
    public.mask_conv_rows = 0;
    public.mask_conv_cols = 0;
    public.mask_conv_mem = public.mask_conv_elem * sizeof(float);
    public.mask_conv_ioffset = 0;
    public.mask_conv_joffset = 0;

    private.point_no = 0;
    private.in_pointer = 0;
    private.d_Row = NULL;
    private.d_Col = NULL;
    private.d_tRowLoc = NULL;
    private.d_tColLoc = NULL;
    private.d_T = NULL;
    private.d_in2 = NULL;
    private.d_in2_sqr = NULL;
    private.d_in_mod = NULL;
    private.d_in_sqr = NULL;
    private.d_conv = NULL;
    private.d_in2_pad = NULL;
    private.d_in2_sub = NULL;
    private.d_in2_sub2_sqr = NULL;
    private.d_tMask = NULL;
    private.d_mask_conv = private.d_mask_conv;
    private.in_partial_sum = NULL;
    private.in_sqr_partial_sum = NULL;
    private.par_max_val = NULL;
    private.par_max_coo = NULL;
}