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

public_struct public;
float *d_in;
int i;
float in_final_sum;

void init_vars() {
    // Aim for ~100MB of data to achieve ~0.01s runtime on modern CPU
    const size_t target_bytes = 100 * 1024 * 1024; // 100 MB
    const size_t element_size = sizeof(float);
    const int elem_count = target_bytes / element_size;

    public.in_mod_elem = elem_count;
    public.in_mod_mem = elem_count * element_size;

    d_in = (float*)malloc(public.in_mod_mem);
    if (!d_in) {
        // In case malloc fails, fallback to smaller size
        public.in_mod_elem = 1024 * 1024; // 1M elements
        public.in_mod_mem = public.in_mod_elem * sizeof(float);
        d_in = (float*)realloc(d_in, public.in_mod_mem);
        if (!d_in) exit(1);
    }

    // Initialize input data with non-zero values to avoid floating point optimizations
    for (int idx = 0; idx < public.in_mod_elem; idx++) {
        d_in[idx] = 1.0f + (idx % 1000) * 0.001f;
    }

    // Initialize other required fields to safe values
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
    public.in_mod_rows = 1;
    public.in_mod_cols = public.in_mod_elem;
    public.in_mod_mem = public.in_mod_elem * sizeof(float);
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
    public.mask_conv_elem = 0;
    public.mask_conv_mem = 0;
    public.mask_conv_ioffset = 0;
    public.mask_conv_joffset = 0;

    i = 0;
    in_final_sum = 0.0f;
}