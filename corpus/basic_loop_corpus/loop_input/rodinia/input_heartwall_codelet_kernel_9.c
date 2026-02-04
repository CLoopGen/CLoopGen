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

public_struct public;
private_struct private;
int ei_new;
int position;
float sum;
int pos_ori;

void init_vars() {
    // Set dimensions to achieve ~100-200ms runtime on modern CPU
    // The inner loop stride is public.in2_sub_rows, and iterates over public.in2_sub_elem elements
    // Aim for total operations around 64M to 128M to take ~0.01s with memory access overhead

    public.in2_sub_cols = 8192;
    public.in2_sub_rows = 8192;
    public.in2_sub_elem = public.in2_sub_rows * public.in2_sub_cols;

    // Allocate d_in2_sub array
    private.d_in2_sub = (float*)calloc(public.in2_sub_elem, sizeof(float));
    if (!private.d_in2_sub) {
        exit(1);
    }

    // Initialize the array with non-zero values to make reduction meaningful
    for (int i = 0; i < public.in2_sub_elem; i++) {
        private.d_in2_sub[i] = 1.0f / (i % 100 + 1);
    }

    // Other fields can be initialized to zero or plausible defaults
    public.tSize = 1;
    public.sSize = 1;
    public.maxMove = 1;
    public.alpha = 0.5f;
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
    public.mask_conv_elem = 0;
    public.mask_conv_mem = 0;
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
    private.d_in2_sub2_sqr = NULL;
    private.d_tMask = NULL;
    private.d_mask_conv = NULL;
    private.in_partial_sum = NULL;
    private.in_sqr_partial_sum = NULL;
    private.par_max_val = NULL;
    private.par_max_coo = NULL;
}