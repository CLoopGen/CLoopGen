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

int i;
public_struct public;
private_struct private[51];

static int *d_endoRow_data = NULL;
static int *d_endoCol_data = NULL;
static int *d_tEndoRowLoc_data = NULL;
static int *d_tEndoColLoc_data = NULL;
static float *d_endoT_data = NULL;

void init_vars() {
    // Initialize public variables to ensure loop runs ~0.01s and stays in bounds
    const int approx_work_per_iteration = 100; // Estimated operations per iteration
    const long target_work = 10000000; // ~10M operations for ~0.01s
    int endoPoints_est = (target_work + approx_work_per_iteration - 1) / approx_work_per_iteration;
    public.endoPoints = (endoPoints_est < 51) ? endoPoints_est : 50; // Clamp to [0,50] since private has size 51

    // Allocate required arrays with sufficient size
    d_endoRow_data = (int*)calloc(public.endoPoints, sizeof(int));
    d_endoCol_data = (int*)calloc(public.endoPoints, sizeof(int));
    d_tEndoRowLoc_data = (int*)calloc(public.endoPoints, sizeof(int));
    d_tEndoColLoc_data = (int*)calloc(public.endoPoints, sizeof(int));
    d_endoT_data = (float*)calloc(public.endoPoints, sizeof(float));

    if (!d_endoRow_data || !d_endoCol_data || !d_tEndoRowLoc_data || 
        !d_tEndoColLoc_data || !d_endoT_data) {
        exit(1);
    }

    // Assign pointers
    public.d_endoRow = d_endoRow_data;
    public.d_endoCol = d_endoCol_data;
    public.d_tEndoRowLoc = d_tEndoRowLoc_data;
    public.d_tEndoColLoc = d_tEndoColLoc_data;
    public.d_endoT = d_endoT_data;

    // Initialize other necessary fields to prevent out-of-bounds access elsewhere
    public.in_mod_elem = 1000; // reasonable size for in_pointer calculation

    // Zero-initialize the private array
    for (int idx = 0; idx < 51; idx++) {
        private[idx].point_no = 0;
        private[idx].in_pointer = 0;
        private[idx].d_Row = NULL;
        private[idx].d_Col = NULL;
        private[idx].d_tRowLoc = NULL;
        private[idx].d_tColLoc = NULL;
        private[idx].d_T = NULL;
        private[idx].d_in2 = NULL;
        private[idx].d_in2_sqr = NULL;
        private[idx].d_in_mod = NULL;
        private[idx].d_in_sqr = NULL;
        private[idx].d_conv = NULL;
        private[idx].d_in2_pad = NULL;
        private[idx].d_in2_sub = NULL;
        private[idx].d_in2_sub2_sqr = NULL;
        private[idx].d_tMask = NULL;
        private[idx].d_mask_conv = NULL;
        private[idx].in_partial_sum = NULL;
        private[idx].in_sqr_partial_sum = NULL;
        private[idx].par_max_val = NULL;
        private[idx].par_max_coo = NULL;
    }
}