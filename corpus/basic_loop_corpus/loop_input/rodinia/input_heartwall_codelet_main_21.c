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

void init_vars() {
    // Initialize data sizes to target ~100-200MB total memory usage for measurable runtime
    const int base_size = 4096;
    const int elem_size = base_size * base_size * sizeof(float);
    
    // Set dimensions
    public.endoPoints = 10;
    public.epiPoints = 40;
    public.allPoints = public.endoPoints + public.epiPoints;  // Must be <= 51 due to private[51]
    
    public.in_mod_elem = base_size;
    public.in_mod_rows = 64;
    public.in_mod_cols = 64;
    public.in_mod_mem = public.in_mod_rows * public.in_mod_cols * sizeof(float);

    // Allocate and initialize arrays
    public.d_epiRow = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_epiCol = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_tEpiRowLoc = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_tEpiColLoc = (int*)calloc(public.epiPoints, sizeof(int));
    public.d_epiT = (float*)calloc(public.epiPoints, sizeof(float));

    for (int idx = 0; idx < public.epiPoints; idx++) {
        public.d_epiRow[idx] = rand() % 100;
        public.d_epiCol[idx] = rand() % 100;
        public.d_tEpiRowLoc[idx] = rand() % 50;
        public.d_tEpiColLoc[idx] = rand() % 50;
        public.d_epiT[idx] = (float)(rand()) / RAND_MAX;
    }

    // Initialize other public fields to avoid undefined behavior
    public.tSize = 100;
    public.sSize = 50;
    public.maxMove = 10;
    public.alpha = 0.5f;
    public.d_endo_mem = 0;
    public.d_endoRow = NULL;
    public.d_endoCol = NULL;
    public.d_tEndoRowLoc = NULL;
    public.d_tEndoColLoc = NULL;
    public.d_endoT = NULL;
    public.d_epi_mem = public.epiPoints * sizeof(int) * 4 + public.epiPoints * sizeof(float);

    public.frames = 1;
    public.frame_no = 0;
    public.frame_rows = 1;
    public.frame_cols = 1;
    public.frame_elem = 1;
    public.frame_mem = sizeof(float);
    public.d_frames = (int*)calloc(1, sizeof(int));
    public.d_frame = (float*)calloc(1, sizeof(float));

    public.in2_rows = 3;
    public.in2_cols = 3;
    public.in2_elem = 9;
    public.in2_mem = 9 * sizeof(float);

    public.ioffset = 0;
    public.joffset = 0;
    public.conv_rows = 64;
    public.conv_cols = 64;
    public.conv_elem = 4096;
    public.conv_mem = 4096 * sizeof(float);

    public.in2_pad_add_rows = 1;
    public.in2_pad_add_cols = 1;
    public.in2_pad_rows = 5;
    public.in2_pad_cols = 5;
    public.in2_pad_elem = 25;
    public.in2_pad_mem = 25 * sizeof(float);

    public.in2_pad_cumv_sel_rowlow = 0;
    public.in2_pad_cumv_sel_rowhig = 4;
    public.in2_pad_cumv_sel_collow = 0;
    public.in2_pad_cumv_sel_colhig = 4;
    public.in2_pad_cumv_sel2_rowlow = 0;
    public.in2_pad_cumv_sel2_rowhig = 4;
    public.in2_pad_cumv_sel2_collow = 0;
    public.in2_pad_cumv_sel2_colhig = 4;

    public.in2_sub_rows = 5;
    public.in2_sub_cols = 5;
    public.in2_sub_elem = 25;
    public.in2_sub_mem = 25 * sizeof(float);

    public.in2_sub_cumh_sel_rowlow = 0;
    public.in2_sub_cumh_sel_rowhig = 4;
    public.in2_sub_cumh_sel_collow = 0;
    public.in2_sub_cumh_sel_colhig = 4;
    public.in2_sub_cumh_sel2_rowlow = 0;
    public.in2_sub_cumh_sel2_rowhig = 4;
    public.in2_sub_cumh_sel2_collow = 0;
    public.in2_sub_cumh_sel2_colhig = 4;

    public.in2_sub2_sqr_rows = 5;
    public.in2_sub2_sqr_cols = 5;
    public.in2_sub2_sqr_elem = 25;
    public.in2_sub2_sqr_mem = 25 * sizeof(float);

    public.tMask_rows = 64;
    public.tMask_cols = 64;
    public.tMask_elem = 4096;
    public.tMask_mem = 4096 * sizeof(float);

    public.mask_rows = 3;
    public.mask_cols = 3;
    public.mask_elem = 9;
    public.mask_mem = 9 * sizeof(float);

    public.mask_conv_rows = 64;
    public.mask_conv_cols = 64;
    public.mask_conv_elem = 4096;
    public.mask_conv_mem = 4096 * sizeof(float);
    public.mask_conv_ioffset = 0;
    public.mask_conv_joffset = 0;

    // Allocate and initialize private structs
    for (int idx = 0; idx < 51; idx++) {
        private[idx].d_in2 = (float*)calloc(public.in2_elem, sizeof(float));
        private[idx].d_in2_sqr = (float*)calloc(public.in2_elem, sizeof(float));
        private[idx].d_in_mod = (float*)calloc(public.in_mod_elem, sizeof(float));
        private[idx].d_in_sqr = (float*)calloc(public.in_mod_elem, sizeof(float));
        private[idx].d_conv = (float*)calloc(public.conv_elem, sizeof(float));
        private[idx].d_in2_pad = (float*)calloc(public.in2_pad_elem, sizeof(float));
        private[idx].d_in2_sub = (float*)calloc(public.in2_sub_elem, sizeof(float));
        private[idx].d_in2_sub2_sqr = (float*)calloc(public.in2_sub2_sqr_elem, sizeof(float));
        private[idx].d_tMask = (float*)calloc(public.tMask_elem, sizeof(float));
        private[idx].d_mask_conv = (float*)calloc(public.mask_conv_elem, sizeof(float));
        private[idx].in_partial_sum = (float*)calloc(1, sizeof(float));
        private[idx].in_sqr_partial_sum = (float*)calloc(1, sizeof(float));
        private[idx].par_max_val = (float*)calloc(1, sizeof(float));
        private[idx].par_max_coo = (int*)calloc(1, sizeof(int));

        for (int j = 0; j < public.in2_elem; j++) {
            private[idx].d_in2[j] = (float)(rand()) / RAND_MAX;
            private[idx].d_in2_sqr[j] = private[idx].d_in2[j] * private[idx].d_in2[j];
        }
        for (int j = 0; j < public.in_mod_elem; j++) {
            private[idx].d_in_mod[j] = (float)(rand()) / RAND_MAX;
            private[idx].d_in_sqr[j] = private[idx].d_in_mod[j] * private[idx].d_in_mod[j];
        }
    }
}