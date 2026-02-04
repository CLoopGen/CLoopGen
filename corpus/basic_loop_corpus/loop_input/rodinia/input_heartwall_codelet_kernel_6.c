#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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
int row;
int col;
int ori_row;
int ori_col;

void init_vars() {
    // Set dimensions to achieve ~100ms execution time on modern CPU
    // Target: 1MB - 256MB data, here we focus on d_in2 and d_in2_pad arrays
    // Aim for padded size around 10k elements -> ~40KB per array (small enough for cache)
    
    public.in2_rows = 128;
    public.in2_cols = 128;
    public.in2_elem = public.in2_rows * public.in2_cols;
    public.in2_mem = public.in2_elem * sizeof(float);
    
    public.in2_pad_add_rows = 1;
    public.in2_pad_add_cols = 1;
    public.in2_pad_rows = public.in2_rows + 2 * public.in2_pad_add_rows;
    public.in2_pad_cols = public.in2_cols + 2 * public.in2_pad_add_cols;
    public.in2_pad_elem = public.in2_pad_rows * public.in2_pad_cols;
    public.in2_pad_mem = public.in2_pad_elem * sizeof(float);

    // Allocate memory
    private.d_in2 = (float*)malloc(public.in2_mem);
    private.d_in2_pad = (float*)malloc(public.in2_pad_mem);

    // Initialize d_in2 with non-zero values
    for (int i = 0; i < public.in2_elem; i++) {
        private.d_in2[i] = (float)(i % 256) / 255.0f;
    }

    // Ensure no out-of-bounds access by validating padding logic
    // The condition checks: 
    //   row > add_rows-1 && row < add_rows+in2_rows
    //   col > add_cols-1 && col < add_cols+in2_cols
    // So valid range is [add_rows, add_rows+in2_rows-1] inclusive

    // All other fields initialized to plausible values
    public.tSize = 100;
    public.sSize = 50;
    public.maxMove = 10;
    public.alpha = 0.85f;
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
    public.in_mod_rows = public.in2_rows;
    public.in_mod_cols = public.in2_cols;
    public.in_mod_elem = public.in2_elem;
    public.in_mod_mem = public.in2_mem;
    public.ioffset = 0;
    public.joffset = 0;
    public.conv_rows = public.in2_rows;
    public.conv_cols = public.in2_cols;
    public.conv_elem = public.in2_elem;
    public.conv_mem = public.in2_mem;
    public.in2_pad_cumv_sel_rowlow = 0;
    public.in2_pad_cumv_sel_rowhig = public.in2_pad_rows - 1;
    public.in2_pad_cumv_sel_collow = 0;
    public.in2_pad_cumv_sel_colhig = public.in2_pad_cols - 1;
    public.in2_pad_cumv_sel2_rowlow = 0;
    public.in2_pad_cumv_sel2_rowhig = public.in2_pad_rows - 1;
    public.in2_pad_cumv_sel2_collow = 0;
    public.in2_pad_cumv_sel2_colhig = public.in2_pad_cols - 1;
    public.in2_sub_rows = public.in2_rows;
    public.in2_sub_cols = public.in2_cols;
    public.in2_sub_elem = public.in2_elem;
    public.in2_sub_mem = public.in2_mem;
    public.in2_sub_cumh_sel_rowlow = 0;
    public.in2_sub_cumh_sel_rowhig = public.in2_rows - 1;
    public.in2_sub_cumh_sel_collow = 0;
    public.in2_sub_cumh_sel_colhig = public.in2_cols - 1;
    public.in2_sub_cumh_sel2_rowlow = 0;
    public.in2_sub_cumh_sel2_rowhig = public.in2_rows - 1;
    public.in2_sub_cumh_sel2_collow = 0;
    public.in2_sub_cumh_sel2_colhig = public.in2_cols - 1;
    public.in2_sub2_sqr_rows = public.in2_rows;
    public.in2_sub2_sqr_cols = public.in2_cols;
    public.in2_sub2_sqr_elem = public.in2_elem;
    public.in2_sub2_sqr_mem = public.in2_mem;
    public.tMask_rows = public.in2_rows;
    public.tMask_cols = public.in2_cols;
    public.tMask_elem = public.in2_elem;
    public.tMask_mem = public.in2_mem;
    public.mask_rows = public.in2_rows;
    public.mask_cols = public.in2_cols;
    public.mask_elem = public.in2_elem;
    public.mask_mem = public.in2_mem;
    public.mask_conv_rows = public.in2_rows;
    public.mask_conv_cols = public.in2_cols;
    public.mask_conv_elem = public.in2_elem;
    public.mask_conv_mem = public.in2_mem;
    public.mask_conv_ioffset = 0;
    public.mask_conv_joffset = 0;

    private.point_no = 0;
    private.in_pointer = 0;
    private.d_Row = NULL;
    private.d_Col = NULL;
    private.d_tRowLoc = NULL;
    private.d_tColLoc = NULL;
    private.d_T = NULL;
    private.d_in2_sqr = NULL;
    private.d_in_mod = NULL;
    private.d_in_sqr = NULL;
    private.d_conv = NULL;
    private.d_in2_sub = NULL;
    private.d_in2_sub2_sqr = NULL;
    private.d_tMask = NULL;
    private.d_mask_conv = NULL;
    private.in_partial_sum = NULL;
    private.in_sqr_partial_sum = NULL;
    private.par_max_val = NULL;
    private.par_max_coo = NULL;
}