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
for (outrow = 0; outrow < compptr->v_samp_factor / 2; outrow++) {
    JSAMPROW outptr_top = output_data[outrow * 2];
    JSAMPROW outptr_bot = output_data[outrow * 2 + 1];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    for (colctr = 0; colctr < output_cols; colctr += 4) {
        // Unroll 4 iterations to increase computational density
        for (int unroll = 0; unroll < 4 && (colctr + unroll) < output_cols; unroll++) {
            int offset = unroll;
            membersum = ((int)(inptr0[offset*2])) + ((int)(inptr0[offset*2+1])) +
                        ((int)(inptr1[offset*2])) + ((int)(inptr1[offset*2+1]));
            neighsum = ((int)(above_ptr[offset*2])) + ((int)(above_ptr[offset*2+1])) +
                       ((int)(below_ptr[offset*2])) + ((int)(below_ptr[offset*2+1])) +
                       ((int)(inptr0[offset*2-1])) + ((int)(inptr0[offset*2+2])) +
                       ((int)(inptr1[offset*2-1])) + ((int)(inptr1[offset*2+2]));
            neighsum += neighsum;
            neighsum += ((int)(above_ptr[offset*2-1])) + ((int)(above_ptr[offset*2+2])) +
                        ((int)(below_ptr[offset*2-1])) + ((int)(below_ptr[offset*2+2]));

            INT32 result = membersum * memberscale + neighsum * neighscale;
            outptr_top[colctr + unroll] = (JSAMPLE)((result + 32768) >> 16);
            outptr_bot[colctr + unroll] = (JSAMPLE)((result + 16384) >> 16); // Slight variation
        }
        inptr0 += 8;
        inptr1 += 8;
        above_ptr += 8;
        below_ptr += 8;
    }
    inrow += 2;
}
}
