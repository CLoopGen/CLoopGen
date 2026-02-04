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
float *d_in;
int row;
int col;
int ori_row;
int ori_col;
int ori_pointer;

void init_vars() {
    // Set parameters to achieve ~100MB of effective data access in the loop
    const int target_size_mb = 100;
    const int bytes_per_access = sizeof(float) + sizeof(float); // two array accesses per iteration
    const int total_elements = (target_size_mb * 1024 * 1024) / bytes_per_access;
    
    // Choose in_mod_cols and in_mod_rows such that their product is about total_elements
    public.in_mod_rows = (int)sqrt(total_elements);
    public.in_mod_cols = total_elements / public.in_mod_rows;

    // Ensure at least 25 to avoid negative indexing with -25 offset
    public.frame_rows = public.in_mod_rows + 50;
    public.frame_cols = public.in_mod_cols + 50;
    public.frame_elem = public.frame_rows * public.frame_cols;
    public.frame_mem = public.frame_elem * sizeof(float);

    // Allocate frame buffer
    public.d_frame = (float*)calloc(public.frame_elem, sizeof(float));
    if (!public.d_frame) exit(1);

    // Initialize alpha between 0 and 1
    public.alpha = 0.5f;

    // Allocate d_in buffer
    public.in_mod_elem = public.in_mod_rows * public.in_mod_cols;
    d_in = (float*)calloc(public.in_mod_elem, sizeof(float));
    if (!d_in) exit(1);

    // Allocate private arrays
    private.point_no = 0;
    private.d_Row = (int*)malloc(sizeof(int));
    private.d_Col = (int*)malloc(sizeof(int));
    if (!private.d_Row || !private.d_Col) exit(1);

    // Set center point so that offsets stay within bounds
    private.d_Row[0] = 30;
    private.d_Col[0] = 30;

    // Zero-initialize remaining fields to avoid undefined behavior
    private.d_tRowLoc = NULL;
    private.d_tColLoc = NULL;
    private.d_T = NULL;
    private.d_in2 = NULL;
    private.d_in2_sqr = NULL;
    private.d_in_sqr = NULL;
    private.d_conv = NULL;
    private.d_in2_pad = NULL;
    private.d_in2_sub = NULL;
    private.d_in2_sub2_sqr = NULL;
    private.d_tMask = NULL;
    private.d_mask_conv = NULL;
    private.in_partial_sum = NULL;
    private.in_sqr_partial_sum = NULL;
    private.par_max_val = NULL;
    private.par_max_coo = NULL;

    // Zero out unused public fields
    memset(&public.tSize, 0, offsetof(public_struct, d_frame) - offsetof(public_struct, tSize));
    memset(&public.frames, 0, sizeof(public_struct) - offsetof(public_struct, frames));
}