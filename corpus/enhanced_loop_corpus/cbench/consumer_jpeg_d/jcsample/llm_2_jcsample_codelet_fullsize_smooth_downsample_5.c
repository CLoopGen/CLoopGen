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

typedef long INT32;

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern int outrow;
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern INT32 membersum;
extern INT32 neighsum;
extern INT32 memberscale;
extern INT32 neighscale;
extern int colsum;
extern int lastcolsum;
extern int nextcolsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr = input_data[outrow];
    above_ptr = input_data[outrow - 1];
    below_ptr = input_data[outrow + 1];

    // Strided memory access: process every second column first, then the odd ones
    // First pass: even columns (0, 2, 4, ...)
    JDIMENSION col;
    for (col = 0; col < output_cols; col += 2) {
        int idx = col;
        colsum = ((int)(inptr[idx])) + 
                 ((int)(above_ptr[idx])) + 
                 ((int)(below_ptr[idx]));
        membersum = ((int)(inptr[idx]));
        int next_idx = idx + 1 < output_cols ? idx + 1 : idx;
        nextcolsum = ((int)(inptr[next_idx])) + 
                     ((int)(above_ptr[next_idx])) + 
                     ((int)(below_ptr[next_idx]));
        neighsum = colsum + (colsum - membersum) + nextcolsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[idx] = (JSAMPLE)((membersum + 32768) >> 16);
    }
    // Second pass: odd columns (1, 3, 5, ...)
    for (col = 1; col < output_cols; col += 2) {
        int idx = col;
        colsum = ((int)(inptr[idx])) + 
                 ((int)(above_ptr[idx])) + 
                 ((int)(below_ptr[idx]));
        membersum = ((int)(inptr[idx]));
        int prev_idx = idx - 1;
        int next_idx = idx + 1 < output_cols ? idx + 1 : idx;
        lastcolsum = ((int)(inptr[prev_idx])) + 
                     ((int)(above_ptr[prev_idx])) + 
                     ((int)(below_ptr[prev_idx]));
        nextcolsum = ((int)(inptr[next_idx])) + 
                     ((int)(above_ptr[next_idx])) + 
                     ((int)(below_ptr[next_idx]));
        neighsum = lastcolsum + (colsum - membersum) + nextcolsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[idx] = (JSAMPLE)((membersum + 32768) >> 16);
    }
}
}
