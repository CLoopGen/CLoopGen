#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

typedef long JLONG;

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern int inrow;
extern int outrow;
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern JLONG membersum;
extern JLONG neighsum;
extern JLONG memberscale;
extern JLONG neighscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to strided array access: process every second column first, then fill gaps (cache-friendly striding)
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    // First pass: even-indexed columns using stride of 4 for better cache line utilization
    JDIMENSION col;
    for (col = 0; col < output_cols; col += 2) {
        int idx = col;

        membersum = inptr0[idx] + inptr0[idx+1] + inptr1[idx] + inptr1[idx+1];
        neighsum = above_ptr[idx] + above_ptr[idx+1] + below_ptr[idx] + below_ptr[idx+1];
        if (idx > 0) {
            neighsum += inptr0[idx-1] + inptr1[idx-1];
        } else {
            neighsum += inptr0[0] + inptr1[0]; // duplicate left edge
        }
        if (idx + 2 < output_cols * 2) {
            neighsum += inptr0[idx+2] + inptr1[idx+2];
        } else {
            neighsum += inptr0[idx+1] + inptr1[idx+1]; // duplicate right edge
        }

        JLONG temp_neighsum = neighsum;
        neighsum += neighsum;
        if (idx > 0) temp_neighsum += above_ptr[idx-1] + below_ptr[idx-1];
        if (idx + 2 < output_cols * 2) temp_neighsum += above_ptr[idx+2] + below_ptr[idx+2];
        else temp_neighsum += above_ptr[idx+1] + below_ptr[idx+1];

        neighsum += temp_neighsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[idx] = (JSAMPLE)((membersum + 32768) >> 16);
    }

    // Second pass: odd-indexed columns with same logic
    for (col = 1; col < output_cols; col += 2) {
        int idx = col;

        membersum = inptr0[idx] + inptr0[idx+1] + inptr1[idx] + inptr1[idx+1];
        neighsum = above_ptr[idx] + above_ptr[idx+1] + below_ptr[idx] + below_ptr[idx+1];
        neighsum += inptr0[idx-1] + inptr1[idx-1];
        if (idx + 2 < output_cols * 2) {
            neighsum += inptr0[idx+2] + inptr1[idx+2];
        } else {
            neighsum += inptr0[idx+1] + inptr1[idx+1];
        }

        JLONG temp_neighsum = neighsum;
        neighsum += neighsum;
        temp_neighsum += above_ptr[idx-1] + below_ptr[idx-1];
        if (idx + 2 < output_cols * 2) {
            temp_neighsum += above_ptr[idx+2] + below_ptr[idx+2];
        } else {
            temp_neighsum += above_ptr[idx+1] + below_ptr[idx+1];
        }

        neighsum += temp_neighsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[idx] = (JSAMPLE)((membersum + 32768) >> 16);
    }
    inrow += 2;
}
}
