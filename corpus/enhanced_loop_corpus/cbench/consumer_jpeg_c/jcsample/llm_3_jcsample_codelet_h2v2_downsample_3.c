#include <stdio.h>

#include <inttypes.h>

typedef unsigned int JDIMENSION;

typedef int boolean;

typedef unsigned short UINT16;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

typedef struct {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
    JDIMENSION width_in_blocks;
    JDIMENSION height_in_blocks;
    int DCT_scaled_size;
    JDIMENSION downsampled_width;
    JDIMENSION downsampled_height;
    boolean component_needed;
    int MCU_width;
    int MCU_height;
    int MCU_blocks;
    int MCU_sample_width;
    int last_col_width;
    int last_row_height;
    JQUANT_TBL *quant_table;
    void *dct_table;
} jpeg_component_info;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern int inrow;
extern int outrow;
extern JDIMENSION outcol;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW outptr;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to strided access: process every other output column first, then fill gaps
// Simulates a transposed-like traversal for cache optimization in specific architectures

JDIMENSION stride = 2;
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    bias = 1;

    // First pass: even indices (strided access by 2)
    for (outcol = 0; outcol < output_cols; outcol += stride) {
        *outptr = (JSAMPLE)((((int)(inptr0[0])) + ((int)(inptr0[1])) + ((int)(inptr1[0])) + ((int)(inptr1[1])) + bias) >> 2);
        outptr += stride;
        inptr0 += 2 * stride;
        inptr1 += 2 * stride;
        bias ^= 3;
    }

    // Reset pointers for second pass: odd indices
    outptr = output_data[outrow] + 1;
    inptr0 = input_data[inrow] + 2;
    inptr1 = input_data[inrow + 1] + 2;
    bias = 1 ^ 3; // Initial bias for odd positions

    // Second pass: odd indices (strided access starting at index 1)
    for (outcol = 1; outcol < output_cols; outcol += stride) {
        *outptr = (JSAMPLE)((((int)(inptr0[0])) + ((int)(inptr0[1])) + ((int)(inptr1[0])) + ((int)(inptr1[1])) + bias) >> 2);
        outptr += stride;
        inptr0 += 2 * stride;
        inptr1 += 2 * stride;
        bias ^= 3;
    }
    inrow += 2;
}
}
