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
extern int outrow;
extern JDIMENSION outcol;
extern JDIMENSION output_cols;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 input reading
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr = input_data[outrow];
        int temp;
        JDIMENSION col = 0;
        // Process two elements at a time for better locality and consecutive output write
        for (; col + 1 < output_cols; col += 2) {
            temp = ((int)(*inptr) + (int)(inptr[1])) >> 1;
            *outptr++ = (JSAMPLE)(temp);
            temp = ((int)(inptr[2]) + (int)(inptr[3])) >> 1;
            *outptr++ = (JSAMPLE)(temp);
            inptr += 4;
        }
        // Handle leftover column if output_cols is odd
        if (col < output_cols) {
            *outptr++ = (JSAMPLE)((((int)(*inptr)) + ((int)(inptr[1]))) >> 1);
        }
    }
}
