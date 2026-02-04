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
int jp1;
int ja1;
int ja2;
int ip1;
int ia1;
int ia2;
int ja;
int jb;
int ia;
int ib;
float s;
int i;
int j;
int row;
int col;

void init_vars() {
    // Set dimensions to achieve ~0.01 seconds runtime
    // The inner loop does conv_rows * conv_cols * (variable inner iterations)
    // We aim for total operations around 1e7 - 1e8 for 0.01s on modern CPU

    public.in2_rows = 256;
    public.in2_cols = 256;
    public.in_mod_rows = 256;
    public.in_mod_cols = 256;
    public.ioffset = 0;
    public.joffset = 0;
    public.conv_rows = 512;
    public.conv_cols = 512;

    public.in2_elem = public.in2_rows * public.in2_cols;
    public.in2_mem = public.in2_elem * sizeof(float);
    public.in_mod_elem = public.in_mod_rows * public.in_mod_cols;
    public.in_mod_mem = public.in_mod_elem * sizeof(float);
    public.conv_elem = public.conv_rows * public.conv_cols;
    public.conv_mem = public.conv_elem * sizeof(float);

    private.d_in2 = (float*)malloc(public.in2_mem);
    private.d_in_mod = (float*)malloc(public.in_mod_mem);
    private.d_conv = (float*)malloc(public.conv_mem);

    if (!private.d_in2 || !private.d_in_mod || !private.d_conv) {
        exit(1);
    }

    for (int idx = 0; idx < public.in2_elem; idx++) {
        private.d_in2[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (int idx = 0; idx < public.in_mod_elem; idx++) {
        private.d_in_mod[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (int idx = 0; idx < public.conv_elem; idx++) {
        private.d_conv[idx] = 0.0f;
    }

    private.point_no = 0;
    private.in_pointer = 0;
    private.d_Row = NULL;
    private.d_Col = NULL;
    private.d_tRowLoc = NULL;
    private.d_tColLoc = NULL;
    private.d_T = NULL;
    private.d_in2_sqr = NULL;
    private.d_in_sqr = NULL;
    private.d_in2_pad = NULL;
    private.d_in2_sub = NULL;
    private.d_in2_sub2_sqr = NULL;
    private.d_tMask = NULL;
    private.d_mask_conv = NULL;
    private.in_partial_sum = NULL;
    private.in_sqr_partial_sum = NULL;
    private.par_max_val = NULL;
    private.par_max_coo = NULL;

    jp1 = 0;
    ja1 = 0;
    ja2 = 0;
    ip1 = 0;
    ia1 = 0;
    ia2 = 0;
    ja = 0;
    jb = 0;
    ia = 0;
    ib = 0;
    s = 0.0f;
    i = 0;
    j = 0;
    row = 0;
    col = 0;
}