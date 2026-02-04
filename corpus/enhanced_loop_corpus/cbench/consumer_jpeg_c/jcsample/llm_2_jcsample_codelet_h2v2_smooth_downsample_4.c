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
extern int inrow;
extern int outrow;
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern INT32 membersum;
extern INT32 neighsum;
extern INT32 memberscale;
extern INT32 neighscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    // Strided memory access: process every second column first, then interleave
    // First pass: even column pairs (0,2), (4,6), ...
    JDIMENSION stride = 4;
    for (colctr = 0; colctr < output_cols; colctr += 2) {
        JSAMPROW e_in0 = inptr0 + colctr;
        JSAMPROW e_in1 = inptr1 + colctr;
        JSAMPROW e_abv = above_ptr + colctr;
        JSAMPROW e_blo = below_ptr + colctr;

        membersum = ((int)(e_in0[0])) + ((int)(e_in0[1])) + ((int)(e_in1[0])) + ((int)(e_in1[1]));
        neighsum = ((int)(e_abv[0])) + ((int)(e_abv[1])) + ((int)(e_blo[0])) + ((int)(e_blo[1])) +
                   (colctr > 0 ? ((int)(e_in0[-1])) : ((int)(e_in0[0]))) +
                   ((int)(e_in0[2])) +
                   (colctr > 0 ? ((int)(e_in1[-1])) : ((int)(e_in1[0]))) +
                   ((int)(e_in1[2]));
        neighsum += neighsum;
        neighsum += (colctr > 0 ? ((int)(e_abv[-1])) : ((int)(e_abv[0]))) +
                    ((int)(e_abv[2])) +
                    (colctr > 0 ? ((int)(e_blo[-1])) : ((int)(e_blo[0]))) +
                    ((int)(e_blo[2]));

        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[colctr] = (JSAMPLE)((membersum + 32768) >> 16);
    }

    // Second pass: odd column pairs (2,4), (6,8), ... to create strided pattern
    for (colctr = 2; colctr < output_cols - 2; colctr += 2) {
        JSAMPROW o_in0 = inptr0 + colctr;
        JSAMPROW o_in1 = inptr1 + colctr;
        JSAMPROW o_abv = above_ptr + colctr;
        JSAMPROW o_blo = below_ptr + colctr;

        membersum = ((int)(o_in0[0])) + ((int)(o_in0[1])) + ((int)(o_in1[0])) + ((int)(o_in1[1]));
        neighsum = ((int)(o_abv[0])) + ((int)(o_abv[1])) + ((int)(o_blo[0])) + ((int)(o_blo[1])) +
                   ((int)(o_in0[-1])) + ((int)(o_in0[2])) +
                   ((int)(o_in1[-1])) + ((int)(o_in1[2]));
        neighsum += neighsum;
        neighsum += ((int)(o_abv[-1])) + ((int)(o_abv[2])) + ((int)(o_blo[-1])) + ((int)(o_blo[2]));

        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[colctr] = (JSAMPLE)((membersum + 32768) >> 16);
    }

    // Handle final column separately
    colctr = output_cols - 1;
    if (colctr > 0) {
        JSAMPROW f_in0 = inptr0 + colctr - 1;
        JSAMPROW f_in1 = inptr1 + colctr - 1;
        JSAMPROW f_abv = above_ptr + colctr - 1;
        JSAMPROW f_blo = below_ptr + colctr - 1;

        membersum = ((int)(f_in0[0])) + ((int)(f_in0[1])) + ((int)(f_in1[0])) + ((int)(f_in1[1]));
        neighsum = ((int)(f_abv[0])) + ((int)(f_abv[1])) + ((int)(f_blo[0])) + ((int)(f_blo[1])) +
                   ((int)(f_in0[-1])) + ((int)(f_in0[1])) +
                   ((int)(f_in1[-1])) + ((int)(f_in1[1]));
        neighsum += neighsum;
        neighsum += ((int)(f_abv[-1])) + ((int)(f_abv[1])) + ((int)(f_blo[-1])) + ((int)(f_blo[1]));

        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[colctr] = (JSAMPLE)((membersum + 32768) >> 16);
    }
    inrow += 2;
}
}
