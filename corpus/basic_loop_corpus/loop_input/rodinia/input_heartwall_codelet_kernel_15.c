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
    int *par_max_coo;
    float *par_max_val;
} private_struct;

public_struct public;
private_struct private;
int ei_new;

void init_vars() {
    // Set tMask_elem to ~10 million elements to achieve ~0.01s runtime (simple zeroing loop)
    public.tMask_elem = 10000000;
    public.tMask_mem = public.tMask_elem * sizeof(float);
    
    // Allocate and initialize arrays as needed
    private.d_tMask = (float*)calloc(public.tMask_elem, sizeof(float));
    if (!private.d_tMask) {
        exit(1);
    }

    // Initialize other required fields to avoid undefined behavior
    public.tMask_rows = 3162;  // approx sqrt(10e6)
    public.tMask_cols = 3162;
    public.mask_elem = 25;
    public.mask_mem = public.mask_elem * sizeof(float);
    public.mask_conv_elem = public.tMask_elem;
    public.conv_elem = 10000;
    public.in2_elem = 100;
    public.frame_elem = 10000;
    public.allPoints = 1000;
    public.endoPoints = 500;
    public.epiPoints = 500;
    public.frames = 10;
    public.frame_no = 0;
    public.frame_rows = 100;
    public.frame_cols = 100;
    public.in2_rows = 10;
    public.in2_cols = 10;
    public.conv_rows = 100;
    public.conv_cols = 100;
    public.in_mod_rows = 100;
    public.in_mod_cols = 100;
    public.in_mod_elem = 10000;
    public.in2_pad_rows = 15;
    public.in2_pad_cols = 15;
    public.in2_pad_elem = 225;
    public.in2_sub_rows = 5;
    public.in2_sub_cols = 5;
    public.in2_sub_elem = 25;
    public.in2_sub2_sqr_rows = 5;
    public.in2_sub2_sqr_cols = 5;
    public.in2_sub2_sqr_elem = 25;

    // Allocate other pointers to prevent crashes (minimal allocation)
    private.d_in2 = (float*)calloc(public.in2_elem, sizeof(float));
    private.d_in2_sqr = (float*)calloc(public.in2_elem, sizeof(float));
    private.d_in_mod = (float*)calloc(public.in_mod_elem, sizeof(float));
    private.d_conv = (float*)calloc(public.conv_elem, sizeof(float));
    private.d_in2_pad = (float*)calloc(public.in2_pad_elem, sizeof(float));
    private.d_in2_sub = (float*)calloc(public.in2_sub_elem, sizeof(float));
    private.d_in2_sub2_sqr = (float*)calloc(public.in2_sub2_sqr_elem, sizeof(float));
    private.d_mask_conv = (float*)calloc(public.mask_conv_elem, sizeof(float));
    private.in_partial_sum = (float*)calloc(public.allPoints, sizeof(float));
    private.in_sqr_partial_sum = (float*)calloc(public.allPoints, sizeof(float));
    private.par_max_val = (float*)calloc(public.allPoints, sizeof(float));
    private.par_max_coo = (int*)calloc(public.allPoints, sizeof(int));

    // Pointers that may be used but are not accessed in the current loop
    private.d_Row = (int*)calloc(public.allPoints, sizeof(int));
    private.d_Col = (int*)calloc(public.allPoints, sizeof(int));
    private.d_tRowLoc = (int*)calloc(public.allPoints, sizeof(int));
    private.d_tColLoc = (int*)calloc(public.allPoints, sizeof(int));
    private.d_T = (float*)calloc(public.allPoints, sizeof(float));
    public.d_frames = (int*)calloc(public.frames, sizeof(int));
    public.d_frame = (float*)calloc(public.frame_elem, sizeof(float));
    public.d_endoRow = (int*)calloc(public.endoPoints, sizeof(int));
    public.d_endoCol = (int*)calloc(public.endoPoints, sizeof(int));
    public.d_tEndoRowLoc = (int*)calloc(public.endoPoints, sizeof(int));
    public.d_tEndoColLoc = (int*)calloc(public.endoPoints, sizeof(int));
    public.d_endoT = (float*)calloc(public.endoPoints, sizeof(float));
    public.d_epiRow = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_epiCol = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_tEpiRowLoc = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_tEpiColLoc = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_epiT = (float*)calloc(public.epiPoints, sizeof(float));

    // Set private scalars
    private.point_no = 0;
    private.in_pointer = 0;

    // Set memory sizes
    public.d_endo_mem = public.endoPoints * sizeof(int);
    public.d_epi_mem = public.epiPoints * sizeof(int);
    public.frame_mem = public.frame_elem * sizeof(float);
    public.in2_mem = public.in2_elem * sizeof(float);
    public.in_mod_mem = public.in_mod_elem * sizeof(float);
    public.conv_mem = public.conv_elem * sizeof(float);
    public.in2_pad_mem = public.in2_pad_elem * sizeof(float);
    public.in2_sub_mem = public.in2_sub_elem * sizeof(float);
    public.in2_sub2_sqr_mem = public.in2_sub2_sqr_elem * sizeof(float);
    public.mask_conv_mem = public.mask_conv_elem * sizeof(float);

    // Set selection bounds for padding/subsampling (safe defaults)
    public.in2_pad_cumv_sel_rowlow = 0;
    public.in2_pad_cumv_sel_rowhig = public.in2_pad_rows;
    public.in2_pad_cumv_sel_collow = 0;
    public.in2_pad_cumv_sel_colhig = public.in2_pad_cols;
    public.in2_sub_cumh_sel_rowlow = 0;
    public.in2_sub_cumh_sel_rowhig = public.in2_sub_rows;
    public.in2_sub_cumh_sel_collow = 0;
    public.in2_sub_cumh_sel_colhig = public.in2_sub_cols;

    // Initialize any other necessary fields to zero
    public.tSize = 100;
    public.sSize = 50;
    public.maxMove = 10;
    public.alpha = 0.5f;
    public.ioffset = 0;
    public.joffset = 0;
    public.mask_conv_ioffset = 0;
    public.mask_conv_joffset = 0;
}