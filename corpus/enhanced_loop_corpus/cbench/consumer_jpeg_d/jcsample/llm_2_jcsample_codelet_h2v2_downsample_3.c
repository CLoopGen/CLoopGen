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
    // Variant 1: Consecutive memory access with manual unrolling of two elements to increase locality
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];
        bias = 1;
        JDIMENSION col = 0;
        // Process two output elements per iteration for improved spatial locality
        for (; col + 1 < output_cols; col += 2) {
            int val0_0 = (int)inptr0[0], val0_1 = (int)inptr0[1];
            int val1_0 = (int)inptr1[0], val1_1 = (int)inptr1[1];
            *outptr++ = (JSAMPLE)(((val0_0 + val0_1 + val1_0 + val1_1 + bias) >> 2));
            bias ^= 3;

            int val0_2 = (int)inptr0[2], val0_3 = (int)inptr0[3];
            int val1_2 = (int)inptr1[2], val1_3 = (int)inptr1[3];
            *outptr++ = (JSAMPLE)(((val0_2 + val0_3 + val1_2 + val1_3 + bias) >> 2));
            bias ^= 3;

            inptr0 += 4;
            inptr1 += 4;
        }
        // Handle remaining element if output_cols is odd
        if (col < output_cols) {
            *outptr++ = (JSAMPLE)((((int)(*inptr0)) + ((int)(inptr0[1])) + ((int)(*inptr1)) + ((int)(inptr1[1])) + bias) >> 2);
            bias ^= 3;
            inptr0 += 2;
            inptr1 += 2;
        }
        inrow += 2;
    }
}
